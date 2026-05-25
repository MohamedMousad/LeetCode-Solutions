class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> available(1e4+5 , 1);
        int sum = 0 ,  ans = 0;
        for (int i = 0 ; i < banned.size() ; i++)
        {
            available[banned[i]] = 0;
        }
        for (int i = 1 ; i <= n;i++ )
        {
            if (available[i] && sum + i <= maxSum )
            {
                sum+=i;
                ans++;
            }
        }
        return ans;
    }
};