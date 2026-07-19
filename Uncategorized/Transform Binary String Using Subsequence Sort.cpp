class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> res(strs.size() , true);
       for (int i = 0 ; i < strs.size(); i++){
           int must_1 = 0 , must_0 = 0;
           int optional_1 = 0 , optional_0 = 0 ; 
           bool can = true;
           vector<int> op_0 , m_1;
            for (int j = 0 ; j < s.size() ; j++){
                if (s[j] == strs[i][j])
                    continue;
                if (strs[i][j] == '?'){
                    if (s[j] == '0'){
                        op_0.push_back(j);
                    }
                    else 
                        optional_1++;
                }
                else{
                    if (s[j] == '0'){
                        if (must_1 ){
                            must_1--;
                            m_1.pop_back();
                        }
                        else if (optional_1)
                            optional_1--;
                        else {
                            can = false ;
                            break;
                        }
                    }
                    else{
                        must_1++;
                        m_1.push_back(j);
                    }
                }
           }
           if (must_0)
               can = false;
           else if (must_1 ){
               while (!m_1.empty() && !op_0.empty()){
                   if (op_0.back() > m_1.back())
                       m_1.pop_back();
                   op_0.pop_back();
               }
               if (!m_1.empty())
                    can = false;
           }
           res[i] = can;
       } 
        return res;
    }
};