class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int sum = 0 , n = startTime.size() ;
        vector<int> pre(n), suf(n);
        for (int i = 0 ; i < n ; i++)
            pre[i] = max(startTime[i] - ( i > 0 ? endTime[i-1] : 0) , (i > 0 ? pre[i-1] : (int)(0)));
        for (int i = n - 1  ; i > 0; i--)
            suf[i] = max(startTime[i]  - endTime[i-1], (i < n - 1 ? suf[i+1] : (int)(0)));
        for (int i = 0 ; i < n - 1 ; i++) {
            sum = max(startTime[i+1] - (endTime[i] - startTime[i]) - (i > 0 ? endTime[i-1] : (int)(0)) , sum);
            int period = endTime[i] - startTime[i];
            if (i - 1 >= 0) {
                if (period <= pre[i-1])
                    sum = max(sum, startTime[i+1] -  (i > 0 ? endTime[i-1] : (int)(0)));
            }
            if (i + 2 < n) {
                if (period <= suf[i+2])
                    sum = max(sum, startTime[i+1] -  (i > 0 ? endTime[i-1] : (int)(0)));
            }
        }
        return sum;
    }
};