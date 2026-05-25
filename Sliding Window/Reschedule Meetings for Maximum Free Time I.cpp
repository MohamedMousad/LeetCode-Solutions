class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int sum = 0 , r = 0 , l = 0 , ans = 0 , last = 0;
        while (r < k){
            sum+=(endTime[r] - startTime[r]);
            r++;
        }
        if (r > startTime.size()) {
            return eventTime - sum;
        }
        while (r < startTime.size()){
            ans = max((startTime[r]-sum) - last , ans);
            sum+=(endTime[r] - startTime[r]);
            sum-= (endTime[l] - startTime[l]);
            last = endTime[l];
            l++;r++;
        }
        return ans;
    }
};