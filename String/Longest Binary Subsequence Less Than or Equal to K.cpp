class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> zeros(s.length());
        for (int i = 0 ; i < s.length(); i++){
            if (s[i] == '0'){
                zeros[i]++;
            }
            if (i > 0) zeros[i]+=zeros[i-1];
        }
        int sum = 0 , mx = 0;
        for (int i = s.length(), shift = -1 ;i >= 0; i-- , shift++){
            if (i < s.length() && s[i] == '1'){
                if (shift < 31 )
                    sum+=(1 << shift);
            }
            int x = 0 ;
            if (i > 0) x+=zeros[i-1];
            if (sum <= k && shift + 1 <= 31) x+=(shift+1);
            mx = max( x , mx);
        }
        return max(mx , zeros[s.length()-1]);
    }
};