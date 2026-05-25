class Solution {
    vector<int> adj[2001];
    vector<int> ans;
    int vis[2001] = {};
    bool dfs(int node){
        vis[node] = 1;
        bool flag = true;
        for (auto& neighbour : adj[node]){
            if (vis[neighbour] == 1)
                return false;
            if(vis[neighbour] == 0)
                flag&=dfs(neighbour);
        }
        vis[node] = 2;
        ans.push_back(node);
        return flag;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0 ;i < prerequisites.size() ; i++){
            int u = prerequisites[i][0] , v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        for (int i = 0 ;i < numCourses ; i++){
            bool flag = true;
            if (!vis[i])
                flag&=dfs(i);
            if (!flag)
                return vector<int>();
        }
        return ans;
    }
};