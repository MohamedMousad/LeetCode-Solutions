class Solution {
public:
    int minOperations(string s) {
        char mn = 'z' ; bool flag = 0;
        for (int i = 0 ; i < s.size(); i++){
            if (s[i] != 'a'){
                mn = min(s[i] , mn);
                flag = 1;
            }
        }
        if(!flag) return 0;
        return int('z' - mn) + 1;
    }
};