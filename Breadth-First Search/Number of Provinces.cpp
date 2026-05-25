class Solution {
    bool vis[201];
    void dfs(int node , vector<vector<int>>& isConnected){
        vis[node] = 1;
        for(int j = 0 ; j < isConnected[node].size() ; j++)
            if (!vis[j] && isConnected[node][j] == 1)
                dfs(j , isConnected);
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        for (int i = 0 ; i < isConnected.size() ; i++){
            if(!vis[i])
                dfs(i , isConnected) , cnt++;
        }
        return cnt;
    }
};
