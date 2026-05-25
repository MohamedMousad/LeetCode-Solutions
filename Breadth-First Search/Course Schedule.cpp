class Solution {
    bool dfs(vector<vector<int>>& adj ,vector<int>& vis , int course ){
        vis[course] = 1;
        bool good = true;
        for (auto neighbour : adj[course]){
            if (vis[neighbour] == 0)
                good&=dfs(adj  , vis , neighbour);
            if (vis[neighbour] == 1)
                return false;
        }
        if (good)
            vis[course] = 2;
        return good;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses , vector<int>());
        vector<int> vis(numCourses);
        for (int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0] , v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        bool good = true;
        for (int i = 0 ; i < numCourses ; i++){
            if (vis[i] == 0)
                good&=dfs(adj , vis , i);
        }
        return good;
    }
};