class Graph {
    vector<pair<int,long long>> adj[101];
    vector<long long> d;
public:
    Graph(int n, vector<vector<int>>& edges) {
        d.assign(n + 5 , LLONG_MAX);
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , w =  edges[i][2];
            adj[u].push_back({v , w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0] , v = edge[1];
        long long w =  edge[2];
        adj[u].push_back({v , w});
    }
    int shortestPath(int node1, int node2) {
        for (int i = 0 ; i < d.size() ; i++)
            d[i] = LLONG_MAX;
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        d[node1] = 0;
        pq.push({0 , node1});
        while (!pq.empty()){
            auto [w , v] = pq.top();
            pq.pop();
            for (auto [neighbour , cost] : adj[v]){
                long long new_cost = w + cost;
                if (new_cost < d[neighbour])
                    d[neighbour] = new_cost , pq.push({new_cost , neighbour});
            }
        }
        return d[node2];   
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */