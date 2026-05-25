class Solution {
    int taken[1005];
    vector<pair<int,int>> adj[1005];
    int mx = 0;
    int mx_val = 0;
    int vis[1000] = {};
    void rec(int i , int time , int curr , vector<int>& values){
        if (i == 0 )
            mx_val = max(mx_val , curr);
        for (auto [node , cost] : adj[i]){
            if (vis[node] < 5 && cost + time <= mx){
                taken[node]++;
                vis[node]++;
                if (taken[node] == 1)
                    curr+=values[node];
                rec(node , time + cost , curr , values);
                taken[node]--;
                if (taken[node] == 0)
                    curr-=values[node];
                vis[node]--;
            }
        }
        return ;
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        mx = maxTime;
        for (int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0], v= edges[i][1] , w = edges[i][2]; 
            adj[u].emplace_back(v , w);
            adj[v].emplace_back(u , w);
        }
        rec(0 , 0, 0 , values);
        return max(values[0] , mx_val);
    }
};