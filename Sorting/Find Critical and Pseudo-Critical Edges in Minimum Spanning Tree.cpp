class Solution {
    int n, m, k;
    vector<int> par;
    vector<int> sz;
    vector<pair<pair<int,int> , pair<int, int>>> edges;

    int find(int child)
    {
        if (par[child] == child) return child;
        return par[child] = find(par[child]);
    }

    bool join(int u, int v)
    {
        u = find(u) , v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u , sz[u] += sz[v];
        return true;
    }

    int mst(int avoid = -1 , const vector<int>& edge = {})
    {
        int cost = 0 , mx_cost = 0 , take = -1;
        if (!edge.empty())
        {
            int u = edge[0] , v = edge[1] , w = edge[2];
            cost += w ;
            join(u, v);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].second.first, v = edges[i].second.second , w = edges[i].first.first , idx = edges[i].first.second;
            if (avoid == idx) continue;
            if (join(u, v))
            {
                cost += w ;
            }
        }
        int root = find(0);
        for (int i = 0 ; i < n; i++)
        {
            if ( find(i) != root ) return -1;
        }
        return cost;
    }

    void init(){
        for (int i = 0; i < n + 5; i++)
        {
            par[i] = i, sz[i] = 1;
        }
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        par.assign(n + 6 , 0);
        sz.assign(n + 6 , 1);
        this->n = n;
        init();
        vector<int> critical , psuedo;
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , w = edges[i][2];
            this->edges.push_back({{w , i} , {u , v}});
        }
        sort(this->edges.begin() , this->edges.end());
        int ans = mst();
        for (int i = 0 ; i < edges.size() ; i++){
            init();
            int curr = mst(i , {});
            if (curr > ans || curr == -1){
                critical.push_back(i);
                continue;
            }
            init();
            curr = mst(i , {edges[i][0] , edges[i][1] , edges[i][2]});
            if (curr == ans)
                psuedo.push_back(i);
        }
        vector<vector<int>> res = {critical , psuedo};
        return res;
    }
};