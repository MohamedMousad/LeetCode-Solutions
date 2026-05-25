class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> answers;
        for (int i = 0; i < s.length() ; i+=k ){
            answers.push_back(s.substr(i , k));
        }
        while (answers.back().length() < k){
            answers.back().push_back(fill);
        }
        return answers;
    }
};