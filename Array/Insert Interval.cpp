class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag = 0;
        for (int i = 0 ; i < intervals.size() ; i++){
            if (!flag && (newInterval[0] <= intervals[i][0] || (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1])
                    ||  (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]))){
                int start = min(newInterval[0] , intervals[i][0]) , end = newInterval[1];
                while (i < intervals.size() && intervals[i][0] <= end)
                    end = max(newInterval[1] , intervals[i][1]) , i++;
                ans.push_back({start , end});
                flag = 1;
            }
            if (i < intervals.size())
                ans.push_back({intervals[i][0] , intervals[i][1]});
        }
        if (!flag)
            ans.push_back(newInterval);
        return ans;
    }
};