class Solution {
public:
    string generateTag(string caption) {
        string ans = "#"; bool flag = 0;
        for (int i = 0 ; i < caption.length() ; i++){
            if (flag == 1 && isalpha(caption[i])){
                ans.push_back(toupper(caption[i]));
                flag = 0;
            }
            else if (caption[i] == ' ' && ans.size() > 1 )flag = 1;
            else if (isalpha(caption[i]))
                ans.push_back(tolower(caption[i]));
            if (ans.size() == 100){
                return ans;
            }
        }
        return ans;
    }
};