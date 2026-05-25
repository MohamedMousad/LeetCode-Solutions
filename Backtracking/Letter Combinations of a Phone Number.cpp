class Solution {
    vector<string> letters = { "" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    vector<string> ans;
    void rec(int i , string& digits , string curr){
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for (int j =0 ; j < letters[(int)(digits[i] - '0')].size() ; j++)
            rec(i+1 , digits , curr + letters[(int)(digits[i] - '0')][j]);
    }
public:
    vector<string> letterCombinations(string digits) {
        rec(0 , digits , "");
        return ans;
    }
};