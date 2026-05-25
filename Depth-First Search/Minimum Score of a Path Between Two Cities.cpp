class Solution {
    bool vis[100005] = {};
    vector<int> adj[100005] = {};
    int mn = INT_MAX;
    void dfs(int source = 1){
        vis[source] = 1;
        for (auto& neighbour : adj[source])
            if (!vis[neighbour])
                dfs(neighbour);
        return ;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        for (int i = 0 ; i < roads.size() ; i++){
            adj[roads[i][0]].push_back(roads[i][1] );
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        dfs();
        for (int i = 0 ; i < roads.size() ; i++){
            int u = roads[i][0] , v = roads[i][1] , w = roads[i][2];
            if (vis[u] || vis[v])
                mn = min(mn , w);
        }
        return mn;
    }
};