class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(int source , int destination , vector<vector<int>>& adj){
        if (source == destination ){
            ans.push_back(path);
            return;
        }
        for (auto& neighbour : adj[source]){
                path.push_back(neighbour);
                dfs(neighbour , destination , adj);
                path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(0 , graph.size() - 1 , graph);
        return ans;
    }
};