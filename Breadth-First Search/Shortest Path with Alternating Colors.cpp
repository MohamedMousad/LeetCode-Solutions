class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n , -1);
        queue<pair<int , pair<int,int>>> nodes;
        nodes.push({0 , {-1 , 0}});
        vector<int> red[101] , blue[101];
        bool visRed[101] = {} , visBlue[101] = {};
        for (int i = 0; i < redEdges.size() ; i++){
            int u = redEdges[i][0] , v = redEdges[i][1];
            red[u].push_back(v);
        }
        for (int i = 0; i < blueEdges.size() ; i++){
            int u = blueEdges[i][0] , v = blueEdges[i][1];
            blue[u].push_back(v);
        }
        visRed[0] = visBlue[0] = 1;
        ans[0] = 0;
        while (!nodes.empty()){
            auto front = nodes.front();
            int u = front.first , color = front.second.first , cost = front.second.second;
            nodes.pop();
            if (color != 1){
                for (auto& node : red[u]){
                    if (!visRed[node]){
                        visRed[node] = 1;
                        if (ans[node] == -1)
                            ans[node] = cost + 1;
                        nodes.push(make_pair(node , make_pair(1 , cost + 1)));
                    }
                }
            }
            if (color != 0){
                for (auto& node : blue[u]){
                    if (!visBlue[node]){
                        visBlue[node] = 1;
                        if (ans[node] == -1)
                            ans[node] = cost + 1;
                        nodes.push(make_pair(node , make_pair(0 , cost + 1)));
                    }
                }
            }
        }
        return ans;
    }
};