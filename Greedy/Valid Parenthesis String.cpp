class Solution {
public:
    bool checkValidString(string s) {
        deque<int> stars;
        deque<pair<char , int>> st;
        for (int i = 0 ; i < s.length(); i++){
            if (s[i] == '*')
                stars.push_back(i);
            else if (!st.empty() && s[i] == ')' && st.back().first == '(')
                st.pop_back();
            else
                st.push_back({s[i] , i});
        }
        while (!stars.empty() && !st.empty() && st.front().first == ')' && stars.front() < st.front().second){
            st.pop_front();
            stars.pop_front();
        }
        while (!stars.empty() && !st.empty() && st.back().first == '(' && stars.back() > st.back().second){
            st.pop_back();
            stars.pop_back();
        }
        return 0 == st.size();
    }
};