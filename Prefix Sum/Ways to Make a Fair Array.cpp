class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size() , cnt = 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 0;
        vector<int> pre(n);
        pre[0] = nums[0];
        pre[1] = nums[1];
        for (int i = 2 ; i < nums.size(); i++)
            pre[i] = pre[i-2] + nums[i];
        for (int i = 0 ; i < nums.size(); i++){
            int odd = 0 , even = 0;
            if (i&1){
                if (i - 1 >= 0)
                    even+=pre[i-1];
                if (i - 2 >= 0 )
                    odd+=pre[i-2];
                if (n-1 > i && ((n-1)%2 == 1))
                    even+=( pre[n-1] - pre[i]);
                else if (n-1 > i && ((n-1)%2 == 0))
                    odd+=( pre[n-1] - (i-1 >= 0 ? pre[i-1] : 0 ));
                if (n-2 > i && ((n-2)%2 == 1))
                    even+=( pre[n-2] - pre[i]);
                else if (n-2 > i && ((n-2)%2 == 0))
                    odd+=( pre[n-2] - (i - 1 >= 0 ? pre[i-1] : 0));
            }
            else {
                if (i - 1 >= 0)
                    odd+=pre[i-1];
                if (i - 2 >= 0 )
                    even+=pre[i-2];
                if (n-1 > i && ((n-1)%2 == 1))
                    even+=( pre[n-1] - (i-1 >= 0 ? pre[i-1] : 0 ));
                else if (n-1 > i && ((n-1)%2 == 0))
                    odd+=( pre[n-1] - pre[i]);
                if (n-2 > i && ((n-2)%2 == 1))
                    even+=( pre[n-2] - (i - 1 >= 0 ? pre[i-1] : 0));
                else if (n-2 > i && ((n-2)%2 == 0))
                    odd+=( pre[n-2] - pre[i]);
            }
            cnt+=(odd == even);
        }
        return cnt;
    }
};