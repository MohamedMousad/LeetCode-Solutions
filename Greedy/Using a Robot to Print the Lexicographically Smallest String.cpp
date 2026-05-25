class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        stack<char> st;
        map<char,int> f;
        for (int i = 0 ; i < s.size();i++){
            f[s[i]]++;
        }
        for (int i = 0 ; i < s.size();){
            if (!st.empty() && st.top() <=  f.begin()->first){
                ans.push_back(st.top());
                st.pop();
            }
            else if (s[i] == f.begin()->first ){
                f[s[i]]--;
                ans.push_back(s[i]);
                i++;
            }
            else{
                f[s[i]]--;
                st.push(s[i]);
                i++;
            }
            if (f[s[i-1]] == 0)
                f.erase(f.find(s[i-1]));
        }
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};