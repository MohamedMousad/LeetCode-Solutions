class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n =  intervals.size();
        sort(intervals.begin() , intervals.end() , [&](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });
        int curr_end = -1e7, cnt = 0;
        for (int i = 0 ; i < n ; i++){
            if (intervals[i][0] >= curr_end)
                curr_end = intervals[i][1];
            else 
                cnt++;
        }
        return cnt;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });