class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin() , cost.rend());
        int sum = 0 , cnt = 0;
        for (int i = 0 ; i < cost.size() ; i++){
            cnt++;
            if (cnt% 3 == 0) 
                continue;
            sum+=cost[i];
        }
        return sum;
    }
};