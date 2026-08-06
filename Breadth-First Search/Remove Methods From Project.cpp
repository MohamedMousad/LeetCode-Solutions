class Solution {
vector<vector<int>> adj = {};
vector<int> vis ;
vector<bool> bad ;
void mark(int src){
    bad[src] = true;
    vis[src] = 1;
    for (auto neighbour : adj[src])
        if (vis[neighbour] == 0)
            mark(neighbour);
}
bool clean(int src ){
    if (bad[src])
        return true;
    vis[src]++;
    bool ch = false;
    for (auto neighbour : adj[src])
        if (vis[neighbour] < 2 )
            ch |=clean(neighbour);
    return ch;
}
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> res;
        adj.resize(n+5);
        vis.resize(n+5);
        bad.resize(n+5);
        for (int i = 0 ; i < invocations.size() ; i++){
            int u = invocations[i][0] , v = invocations[i][1];
            adj[u].push_back(v);
        }
        mark(k);
        bool good = false;
        for (int i = 0 ; i < n ; i++){
            if (vis[i] == 0)
                good |= clean(i);
        }
        for (int i = 0 ; i < n ; i++){
            if (!bad[i] || good)
                res.push_back(i);
        }
        return res;
    }
};