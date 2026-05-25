class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> mono;
        vector<int> ans(temperatures.size());
        for (int i = 0 ; i < temperatures.size(); i++){
            while (!mono.empty() && temperatures[i] > mono.top().second)
                ans[mono.top().first] = i - mono.top().first , mono.pop();
            mono.push({i, temperatures[i]});
        }
        return ans;
    }
};