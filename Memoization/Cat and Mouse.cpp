class Solution {
    int dp[55][55][2505];
    int rec(int mouse, int cat , int turn , vector<vector<int>>& graph){
        int& ret = dp[mouse][cat][turn]; 
        if (turn > 300)
            return ret =  0;
        if (mouse == 0)
            return ret = 1;
        if (mouse == cat)
            return ret = 2;
        if (~ret) return ret;
        if (turn%2 == 0){
            int ch = 2;
            for(auto& node : graph[mouse]){
                int current = rec(node , cat, turn+1, graph);
                if (current == 1)
                    return ret = 1;
                if (current == 0 && ch == 2)
                    ch = current;
            }
            return ret = ch;
        }
        else {
            int ch = 1;
            for(auto& node : graph[cat]){
                if (node == 0) continue;
                int current = rec(mouse, node, turn+1, graph);
                if (current == 2)
                    return ret = 2;
                if (current == 0 && ch == 1)
                    ch = current;
            }
            return ret = ch;
        }
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp , -1 , sizeof dp);
        return rec(1 , 2 , 0 , graph);
    }
};