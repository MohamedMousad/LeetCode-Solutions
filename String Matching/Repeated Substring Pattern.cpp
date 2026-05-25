class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1 ; i <= sqrt(n) ; i++){
            bool good = true;
            int sz2 = n / i ;
            if (n%i == 0){
                string t = s.substr(0, i);
                if (i != n){
                    for (int j = i ; j < s.size() ; j+=i){
                        if (t != s.substr(j , i)){
                            good = false;
                            break;
                        }
                    }
                    if (good) return true;
                }
                if (sz2 != n ){
                    t = s.substr(0, sz2);
                    good = true;
                    for (int j = sz2 ; j < s.size() ; j+=sz2){
                        if (t != s.substr(j , sz2)){
                            good = false;
                            break;
                        }
                    }
                    if (good) return true;
                }
            }
        }
        return false;
    }
};