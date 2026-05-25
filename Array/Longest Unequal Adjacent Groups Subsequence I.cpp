class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans ;
        int prev = -1;
        for (int i = 0 ; i < groups.size() ; i++){
            if (groups[i] != prev) {
                ans.push_back(words[i]);
                prev = groups[i];
            }
        }
        return ans;
        
    }
};