class Solution {
public:
    int numSteps(string s) {
        int op = 0 ; 
        for (int i = s.length() - 1 ; i >= 0 ; ){
            if (i == 0 && s[i] == '1')
                break;
            if (s[i] == '0'){
                op++ , i--;
            }
            else{
                op++;
                while(i >= 0 && s[i] == '1' ){
                    i--,op++;
                }
                if (i >= 0 && s[i] == '0')
                    s[i] = '1';
            }
        }
        return op;
    }
};