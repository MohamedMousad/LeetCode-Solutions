class Solution {
    vector<pair<int,int>> adj[101];
    vector<int> d;
    int N , mx;
    int dijkstra(int node){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        d[node] = 0;
        pq.push({0 , node});
        while (!pq.empty()){
            auto [w , v] = pq.top();
            pq.pop();
            for (auto [neighbour , cost] : adj[v]){
                int new_cost = w + cost;
                if (new_cost < d[neighbour] && new_cost <= mx)
                    d[neighbour] = new_cost , pq.push({new_cost , neighbour});
            }
        }
        int cnt = 0;
        for (int i= 0 ; i < N;i++){
            if (d[i] != INT_MAX)
                cnt++;
        }
        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , w =  edges[i][2];
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        N = n , mx = distanceThreshold;
        int ans = 0 , mn = INT_MAX;
        for (int i = n-1 ; i >= 0 ; i--){
            d.assign(n+1 , INT_MAX);
            int curr = dijkstra(i);
            if (mn > curr)
                ans = i , mn = curr;
        }
        return ans;
    }
};
