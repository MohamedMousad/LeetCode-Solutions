class Solution {
public:
    bool checkString(string s) {
        int i = 0 ; 
        while (i < s.size() && s[i] == 'a') i++;
        while (i < s.size() && s[i] == 'b') i++;
        return i == s.size();
    }
};