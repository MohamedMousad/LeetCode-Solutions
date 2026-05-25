class Solution {
public:
    int maxDifference(string s) {
        int a[26] = {};
        int max_odd = -1e9 , min_even = 1e9;
        for (int i = 0 ; i < s.length() ; i++){
            a[s[i] - 'a']++;
        }
        for (int i = 0 ; i < 26 ; i++){
            if (a[i] != 0 ){
                if (a[i]&1){
                    max_odd = max(max_odd , a[i]);
                }
                else{
                    min_even = min(min_even , a[i]);
                }
            }
        }
        int ans = max_odd - min_even;
        return ans;
    }
};