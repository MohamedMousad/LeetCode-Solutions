class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = heights[0];
        if (heights.size() <= 1) return res;
        stack<pair<int,int>> mono;
        vector<pair<int,int>> ans(heights.size());
        for (int i = 0 ; i < heights.size(); i++){
            while (!mono.empty() && heights[i] < mono.top().second)
                ans[mono.top().first].second = i , mono.pop();
            mono.push({i, heights[i]});
        }
        while (!mono.empty())
            ans[mono.top().first].second = heights.size() , mono.pop();
        
        for (int i = heights.size()-1 ; i >= 0; i--){
            while (!mono.empty() && heights[i] < mono.top().second)
                ans[mono.top().first].first = i , mono.pop();
            mono.push({i, heights[i]});
        }
        while (!mono.empty())
            ans[mono.top().first].first = -1 , mono.pop();
        
        for (int i = 0 ; i < ans.size(); i++)
            res = max(res , (ans[i].second - ans[i].first - 1 )*heights[i]);

        return res;
    }
};