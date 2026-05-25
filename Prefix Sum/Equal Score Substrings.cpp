class Solution {
public:
    bool scoreBalance(string s) {
        int sum1 = 0 , sum2 = 0 ;
        for (int i = 0 ; i < s.size() ; i++)
            sum1+=(s[i] - 'a' + 1);
        for (int i = s.size() - 1 ; i > 0 ; i--){
            sum1-=(s[i] - 'a' + 1);
            sum2+=(s[i] - 'a' + 1);
            if (sum1 == sum2) return true;
        }
        return false;
    }
};