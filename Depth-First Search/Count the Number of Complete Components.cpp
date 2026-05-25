class Solution {
    int vis[55]= {};
    vector<int> adj[55];
    int GetComponentSize(int src){
        vis[src]++;
        int sum = 1;
        for (auto child: adj[src]){
            if (vis[child] == 0)
                sum+=GetComponentSize(child);
        }
        return sum;
    }
    bool isComplete(int src , int sz){
        bool good = ( adj[src].size() == (sz - 1));
        vis[src]++;
        for (auto child: adj[src]){
            if (vis[child] == 1)
                good&=isComplete(child , sz);
        }
        return good;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
        for (int i = 0 ; i < n; i++){
            if (vis[i] == 0){
                int sz = GetComponentSize(i);
                cnt +=isComplete(i , sz);
            }
        }
        return cnt;
    }
};