class Solution {
public:
    int numSub(string s) {
        long long ans = 0  , mod = 1e9 + 7;
        for (int i = 0 ; i < s.size() ; i++){
            long long sz =  0;
            while (i < s.size() && s[i] == '1') sz++ , i++;
            ans += ((sz*(sz+1)>>1));
            ans%=mod;
        }
        return ans;
    }
};