class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0] , end = intervals[0][1];
        for (int i = 1 ; i < intervals.size() ; i++){
            while (i < intervals.size() && intervals[i][0] <= end)
                end = max(intervals[i++][1] , end);
            ans.push_back({start , end});
            if (i < intervals.size()) start = intervals[i][0] , end = intervals[i][1];
        }
        if (ans.empty() || start > ans.back()[0] )
            ans.push_back({start , end});
        return ans;
    }
};