class Solution {
public:
    int possibleStringCount(string word) {
        short cnt = 1  , n = word.length() - 1;
        for (int i = 0 ; i < n; i++){
            if (word[i] == word[i+1])
                cnt++;
        }
        return cnt;
    }
};