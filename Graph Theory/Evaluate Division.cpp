class Solution {
    unordered_map<string,vector<pair<string,long double>>> g;
    unordered_map<string , bool> vis;
    long double dfs(string& start_node , string& curr , string& end_node , long double cost ){
        vis[curr] = 1;
        long double ans = -1;
        if (curr == end_node) return cost;
        for (auto& [ neighbour , w ] : g[curr]){
            if (!vis[neighbour]){
                    ans = max( dfs(start_node , neighbour , end_node ,curr == start_node ? w : cost*w) , ans);
            }
        }
        return ans;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0 ; i < equations.size() ; i++){
            g[equations[i][0]].emplace_back(equations[i][1] , values[i]);
            g[equations[i][1]].emplace_back(equations[i][0] , 1.0/ values[i]);
        }
        vector<double> ans;
        for (int i = 0 ;i < queries.size() ; i++){
            if (g.count(queries[i][0]) == 0){
                ans.push_back(-1.0);
                continue;
            }
            if (queries[i][0] == queries[i][1]){
                ans.push_back(1.0);
                continue;
            }
            vis.clear();
            ans.push_back(dfs(queries[i][0] , queries[i][0] , queries[i][1] , 0));
        }
        return ans;
    }
};