class Solution {
    bool vis[200001] = {};
    vector<int> adj[200001] = {};
    bool dfs(int source , int destination){
        if (source == destination ) return 1;
        vis[source] = 1;
        bool ok = false;
        for (auto& neighbour : adj[source])
            if (!vis[neighbour])
                ok|=dfs(neighbour , destination);
        return ok;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back( edges[i][1]);
            adj[edges[i][1]].push_back( edges[i][0]);
        }
        return dfs(source, destination);
    }
};