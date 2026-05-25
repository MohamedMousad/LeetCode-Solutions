class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int freq [32] = {} , freq2 [32] = {};
        long long ans1 = 0 , ans2 = 0;
        for (auto& num : nums){
            bool pos = 1;
            if (num < 0) pos = 0;
            long long n = abs((long long)(num));
            for (int i = 0 ; i <= 31 ;i++ ){
                if (pos)
                    freq[i]+=(((1LL<<i) & n ) != 0LL);
                else 
                    freq2[i]+=(((1LL<<i) & n ) != 0LL);
            }
        }
        for (int i = 31 ; i >= 0 ; i--){
            freq[i] = freq[i]%3LL;
            if (freq[i])
                ans1+=((long long)(1LL<<i));
        }
        for (int i = 31 ; i >= 0 ; i--){
            freq2[i] = freq2[i]%3LL;
            if (freq2[i])
                ans2+=((long long)(1LL<<i));
        }
        if (ans1 > 0 ) return ans1;
        else return (int)(-ans2);
    }
};