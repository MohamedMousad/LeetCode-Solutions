class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for (int i = 0 ; i < landStartTime.size() ; i++){
            int time = 0;
            for (int j = 0 ; j < waterStartTime.size() ; j++){
                time = min( waterStartTime[j] , landStartTime[i]) + (waterStartTime[j] <= landStartTime[i] ? waterDuration[j] : landDuration[i]);
                if (time <= max( waterStartTime[j] , landStartTime[i]))
                    time = max( waterStartTime[j] , landStartTime[i]);
                time +=(waterStartTime[j] <= landStartTime[i] ? landDuration[i] : waterDuration[j]);
                ans = min(ans , time);
            }
        }
        return ans;
    }
};