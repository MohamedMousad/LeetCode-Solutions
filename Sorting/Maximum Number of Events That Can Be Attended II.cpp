class Solution {
public:
    int rec(int i , int k , vector<vector<int>>& dp , vector<vector<int>>& events ) {
        if (i == events.size() || k == 0) return 0;
        int& ret = dp[i][k];
        if (~ret) return ret;
        // take
        int next = upper_bound(events.begin() , events.end() , events[i][1] ,
         [&](int value , vector<int>& b){ return value < b[0];}) - events.begin();
        int ch1 = rec( next , k-1 , dp , events) + events[i][2];
        // leave
        int ch2 = rec(i+1 , k , dp , events);
        return ret = max(ch1 , ch2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        vector<vector<int>> dp(events.size() , vector<int>(k+1 , -1));
        return rec(0 , k , dp , events);
    }
};