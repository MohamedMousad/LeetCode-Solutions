class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        deque<int> d;
        vector<int> ans(heights.size());
        for (int i= heights.size() - 1 ; i >= 0 ; i--){
            auto it = lower_bound(d.begin() , d.end() , heights[i]);
            if (!d.empty())
                ans[i] = it - d.begin() + 1 - (it == d.end());
            while (!d.empty() && heights[i] > d.front()) d.pop_front();
            d.push_front(heights[i]);
        }
        return ans;
    }
};