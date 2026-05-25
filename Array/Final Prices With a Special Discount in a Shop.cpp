class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>> mono;
        vector<int> ans(prices.size());
        for (int i = 0 ; i < prices.size(); i++){
            while (!mono.empty() && prices[i] <= mono.top().second)
                ans[mono.top().first] = mono.top().second - prices[i] , mono.pop();
            mono.push({i, prices[i]});
        }
        while (!mono.empty())
             ans[mono.top().first] = mono.top().second, mono.pop();
        return ans;
    }
};