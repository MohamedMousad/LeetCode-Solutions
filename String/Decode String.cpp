class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0 ; i < s.size(); i++){
            st.push(s[i]);
            if (!st.empty() && st.top() == ']'){
                st.pop();
                string t , num , ans;
                while (!st.empty() && st.top() != '[')
                    t.push_back(st.top()) , st.pop();
                st.pop();
                while (!st.empty() && st.top() >= '0' && st.top() <= '9')
                    num.push_back(st.top()) , st.pop();
                reverse(t.begin() , t.end());
                reverse(num.begin() , num.end());
                int occ = stoi(num);
                while (occ--)
                    ans+=t;
                for (int j  = 0 ; j < ans.size() ; j++)
                    st.push(ans[j]);
            }
        }
        string res ;
        while(!st.empty())
            res.push_back(st.top()) , st.pop();
        reverse(res.begin() , res.end());
        return res;
    }
};