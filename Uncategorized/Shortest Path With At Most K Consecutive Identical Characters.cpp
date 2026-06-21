class Solution {
    vector<pair<int,int>> adj[50005];
    int d[50005][55];
    int N, K;
    int dijkstra(int node , string label){
        for (int i = 0 ; i < N ; i++){
            for (int j = 0 ;j <= K ; j++){
                if (i == 0)
                    d[i][j] = 0;
                else 
                    d[i][j] = INT_MAX;   
            }
        }
        if (node == N-1)
            return 0;
        priority_queue<pair< pair<int,int> , int> , vector<pair< pair<int,int> , int>> , greater<pair< pair<int,int> , int>>> pq;
        d[node][1] = 0;
        pq.push({ {0 , 1} , node});
        while (!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int w = front.first.first , c = front.first.second , v = front.second;
            for (auto [neighbour , cost] : adj[v]){
                int new_cost = w + cost , new_c = c + (label[v] == label[neighbour]);
                if (label[v] != label[neighbour])
                    new_c = 1;
                if (new_cost < d[neighbour][new_c] && new_c <= K )
                    d[neighbour][new_c] = new_cost , pq.push({{new_cost , new_c} ,  neighbour});
            }
        }
        int ans = INT_MAX;
        for (int i = 1 ; i <= K ; i++){
            ans = min(ans , d[N-1][i]);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , w =  edges[i][2];
            adj[u].push_back({v , w});
        }
        N= n , K = k;
        return dijkstra(0 , labels );
    }
};