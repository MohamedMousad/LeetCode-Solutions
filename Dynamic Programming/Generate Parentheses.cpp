class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int total = 2LL*n , mask = (1LL<<total) ;
        for (int i = 0; i < mask ; i++){
            string s;
            int cnt = 0;
            for (int j = 0 ; (1LL<<j) < mask ; j++ ){
                if (i & (1LL<<j))
                    s.push_back('(') , cnt++;
                else 
                    s.push_back(')') , cnt--;
                if (cnt < 0 )
                    break;
            }
            if (cnt == 0)
                ans.push_back(s);
        }
        return ans;
    }
};