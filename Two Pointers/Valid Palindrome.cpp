class Solution {
public:
    bool isPalindrome(string s) {
        string t; 
        for (int i = 0 ; i < s.size() ; i++){
            if (isalpha(s[i]))
                t.push_back(tolower(s[i]));
            else if (s[i] - '0' >= 0 && s[i] - '0' <= 9 )
                t.push_back(s[i]);
        }
        for (int l= 0 , r = t.size() - 1 ; l <= r ; l++, r--){
            if (t[l] != t[r])
                return false;
        }
        return true;
    }
};