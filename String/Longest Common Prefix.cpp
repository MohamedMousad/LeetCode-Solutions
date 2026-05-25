class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ;
        for (int j = 0 ; j < 200 ; j++){
            char c = '1';
            if (j < strs[0].size()) c = strs[0][j];
            for (int i = 0 ; i < strs.size() ; i++){
                if (!(c != '1' && j < strs[i].size() && strs[i][j] == c))
                    return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};