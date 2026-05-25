class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        while (!s.empty() && s.back() == ' ') s.pop_back();
        while (!s.empty() && s.back() != ' ') s.pop_back(), cnt++;
        return cnt;
    }
};