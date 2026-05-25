class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        s.push_back(' ');
        for (int i =  s.size() - 1  ; i >= 0 ; i--){
            if (s[i] != ' '){
                st.push(s[i]);
                if (i == 0) goto addWord;
            }
            else{
                addWord:
                if (!ans.empty() && !st.empty()) ans.push_back(' ');
                while (!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return  ans;
    }
};