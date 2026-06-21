class Solution {
    vector<int> adj[100005];
    long long dfs(int node , vector<int>& baseTime){
        if (adj[node].empty())
            return baseTime[node];
        long long mn = LLONG_MAX, mx = LLONG_MIN ;
        for (auto neighbour : adj[node]){
            long long curr = dfs(neighbour , baseTime);
            mn = min(curr , mn);
            mx = max(curr , mx);
        }
        long long ownDuration = (mx - mn ) + baseTime[node];
        return mx + ownDuration ;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
        }
        return dfs(0 , baseTime );
    }
};