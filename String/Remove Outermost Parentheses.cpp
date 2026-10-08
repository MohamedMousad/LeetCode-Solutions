class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        for (int i = 0 ; i < s.length() ; i++){
            int t = 0;
            if (s[i] == '(') i++;
            while (i < s.length() && (s[i] == '(' || t > 0)){
                if (s[i] == '(')
                    t++;
                else
                    t--;
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};