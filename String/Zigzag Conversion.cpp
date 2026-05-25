class Solution {
public:
    string convert(string s, int numRows) {
        vector<queue<char>> words(numRows);
        bool reverse = false;
        for (int i = 0 , j = 0 ; i < s.size() ; i++){
            words[j].push(s[i]);
            if (j == 0 && j == numRows-1) continue;
            if ((j == numRows - 1 && !reverse) || (j == 0 && reverse) ) reverse ^=1;
            if(reverse) j--; else j++;
        }
        string ans;
        for (int i = 0 ; i < numRows ; i++){
            while (!words[i].empty()) ans.push_back(words[i].front()) , words[i].pop();
        }
        return ans;
    }
};