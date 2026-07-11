class Solution {
    int n, m, k;
    vector<int> par;
    vector<int> sz;
    vector<pair<int, pair<int, int>>> edges;
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

    int mst()
    {
        int cost = 0 ;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].second.first, v = edges[i].second.second , w = edges[i].first;
            if (join(u, v))
                cost+=w;
        }
        return cost;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        par.assign(points.size() + 6 , 0);
        sz.assign(points.size() + 6 , 1);
        for (int i = 0; i < points.size() + 5; i++)
        {
            par[i] = i, sz[i] = 1;
        }
        for (int i = 0 ; i < points.size() ; i++){
            for (int j = i+1 ; j < points.size(); j++){
                edges.push_back({ abs( points[i][0] - points[j][0]) +abs( points[i][1] - points[j][1])  , {i , j}});
            }
        }
        sort(edges.begin() , edges.end());
        return mst();
    }
};