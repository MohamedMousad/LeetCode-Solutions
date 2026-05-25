class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        for (int i = 1 ; i < prices.size() ; i++){
            long long cnt = 0;
            while (i < prices.size() && prices[i] - prices[i-1] == -1)
                cnt++ , i++;
            ans+=((cnt*(cnt+1))>>1);
        }
        return ans;
    }
};