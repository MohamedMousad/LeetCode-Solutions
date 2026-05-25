class Solution {
public:
    int minOperations(string s) {
        int cost1 = 0 , cost2 = 0;
        for (int i = 0; i < s.length() ; i++){
            if (((i&1) && s[i] == '0') || ((i&1) == 0 && s[i] == '1'))
                cost1++;
            if (((i&1) && s[i] == '1') || ((i&1) == 0 && s[i] == '0'))
                cost2++;
        }
        return min(cost1 ,cost2);
    }
};