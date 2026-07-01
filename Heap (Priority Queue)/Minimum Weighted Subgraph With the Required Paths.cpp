class Solution {
    #define ll long long
    void dijkstra(int& dest, vector<ll>& d , vector<vector<pair<int,int>>>& adj){
        priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>>> pq;
        pq.push({0 , dest});
        d[dest] = 0;
        while (!pq.empty()){
            auto front = pq.top();
            pq.pop();
            ll w  = front.first, v = front.second;
            if (w > d[v]) 
                continue;
            for (auto& [neighbour , cost] : adj[v]){
                ll new_cost = w + cost;
                if (new_cost < d[neighbour])
                    d[neighbour] = new_cost , pq.push({new_cost , neighbour});
            }
        }
        return;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<ll> d1(n+5 , LLONG_MAX) , d2(n+5 , LLONG_MAX) , d3(n+5 , LLONG_MAX);
        vector<vector<pair<int,int>>> adj1(n+5) , adj2(n+5);
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , w = edges[i][2];
            adj1[u].push_back({v , w});
            adj2[v].push_back({u , w});
        }
        dijkstra(src1 , d1 ,adj1);
        dijkstra(src2 , d2 ,adj1);
        dijkstra(dest , d3 ,adj2);
        long long ans = LLONG_MAX;
        for (int i = 0 ; i < n ; i++){
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || d3[i] == LLONG_MAX)
                continue;
            long long cost = d1[i] + d2[i] + d3[i];  
            ans = min(ans , cost);
        }
        return ans == LLONG_MAX ? -1LL : ans ;
    }
};