class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i = 0 ; i < colors.size();){
            int sum = 0, mx = 0 , flag = -1;
            do{
                sum+=neededTime[i] , mx = max(mx , neededTime[i]) , i++ , flag++;
            } while (( i < colors.size() && colors[i] == colors[i-1]));
            if (flag) ans +=(sum - mx);
        } 
       return ans;
    }
};