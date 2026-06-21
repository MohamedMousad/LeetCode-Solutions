class Solution {
    vector<pair<int,int>> adj[101];
    vector<int> d;
    int N;
    int dijkstra(int node){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        d[node] = 0;
        pq.push({0 , node});
        while (!pq.empty()){
            auto [w , v] = pq.top();
            pq.pop();
            for (auto [neighbour , cost] : adj[v]){
                int new_cost = w + cost;
                if (new_cost < d[neighbour])
                    d[neighbour] = new_cost , pq.push({new_cost , neighbour});
            }
        }
        int mx = 0;
        for (int i= 1 ; i <= N;i++){
            if (d[i] == INT_MAX)
                return -1;
            mx = max(mx , d[i]);
        }
        return mx;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (int i = 0 ; i < times.size() ; i++){
            int u = times[i][0] , v = times[i][1] , w =  times[i][2];
            adj[u].push_back({v , w});
        }
        N = n;
        d.assign(n+1 , INT_MAX);
        return dijkstra(k);
    }
};