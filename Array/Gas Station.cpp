class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int sum = 0;
        for (int i = 0; i < cost.size() ;i++)
            diff[i] = gas[i] - cost[i] , sum+=diff[i];

        if (sum < 0 )
            return -1;
        sum = 0;
        int start = 0;
        for (int i = 0 ; i < diff.size() ; i++){
            sum+=diff[i];
            if (sum < 0 )
                sum = 0 , start = i + 1 ; 
        }
        return start;
    }
};