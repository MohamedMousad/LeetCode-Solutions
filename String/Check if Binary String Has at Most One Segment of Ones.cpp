class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0 ;
        for (int i = 0; i < s.length() ;)
        {
            if (s[i] == '1'){
                while (i < s.length() && s[i] == '1'){
                    i++;
                }
                cnt++;
            }
            else 
                i++;
        }
        return cnt <= 1;
    }
};