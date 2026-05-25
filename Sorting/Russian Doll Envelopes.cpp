class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , [&](const vector<int>& a , const vector<int>& b ){
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        vector<int> ans;
        int i = 0;
        for (const auto& envelope : envelopes ){
            auto it = lower_bound(ans.begin() , ans.end() , envelope[1]);
            if (it == ans.end())
                ans.push_back(envelope[1]);
            else 
                *it = envelope[1];
        }
        return ans.size();
    }
};