class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        for (int i = 0 ;i < s.length() ; i++){
            if (!st.empty() && s[i] == ')' && st.top().first == '('){
                st.pop();
                continue;
            }
            st.push({s[i] , i});
        }
        int last = s.length() , mx = 0;
        while (!st.empty()){
            mx = max(mx , last - st.top().second - 1);
            last = st.top().second;
            st.pop();
        }
        mx = max(last , mx );
        return mx;
    }
};