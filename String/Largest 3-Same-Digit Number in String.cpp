class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = -1;
        for (short i = 0 ; i < num.size() - 2 ; i++){
            if (num[i] == num[i+1] && num[i+1] == num[i+2] && ((num[i] - '0') > mx)){
                mx = (num[i] - '0');
            }
        }
        if (mx == -1)
            return "";
        else {
            char c = mx + '0';
            string ans = "";
            ans.push_back(c);
            ans.push_back(c);
            ans.push_back(c);
            return ans;
        }
    }
};