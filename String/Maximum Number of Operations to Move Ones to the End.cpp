class Solution {
public:
    int maxOperations(string s) {
        int n = s.size() , cnt  = 0 , ans = 0  ;
        bool flag = 0;
        for (int i =  0 ; i < n ; i++){
            while (i <  n && s[i] == '1') cnt++ , i++ , flag = true;
            if (i < n && flag && s[i] == '0') ans+=cnt , flag = false;
        }
        return ans;
    }
};