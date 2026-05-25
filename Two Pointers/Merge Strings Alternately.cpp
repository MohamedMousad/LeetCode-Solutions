class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0 , r = 0;
        string ans;
        while (l < word1.size() && r < word2.size()){
            ans.push_back(word1[l++]);
            ans.push_back(word2[r++]);
        }
        while (l < word1.size())
            ans.push_back(word1[l++]);
        while (r < word2.size())
            ans.push_back(word2[r++]);
        return ans;
    }
};