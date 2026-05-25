class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        for (int i = 0 , j = 0 , cnt = 0; i < s.size() ;){
            if (cnt >= words.size()) return false;
            if (words[cnt][j] == s[i]){
                i++ ,j++;
            }
            else 
                return false;
            if (i == s.size() && j < words[cnt].size())
                return false;
            if (words[cnt].size() == j)
                cnt++ , j = 0;
        }
        return true;
    }
};