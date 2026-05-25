class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0 ; i < n ; i++){
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                st.push(stoi(tokens[i]));
            else{
                int second = st.top(); st.pop(); int first = st.top() ; st.pop();
                int ans = 0;
                if (tokens[i] == "+" )
                    st.push(first + second);
                else if (tokens[i] == "-" )
                    st.push(first - second);
                else if (tokens[i] == "*" )
                    st.push(first * second);
                else 
                    st.push(first / second);
            }
        }
        return st.top();
    }
};