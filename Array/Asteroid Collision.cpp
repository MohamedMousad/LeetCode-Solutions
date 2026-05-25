class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto& num : asteroids){
            if (num < 0){
                while (!st.empty() && st.top() < -num && st.top() > 0 )
                    st.pop();
                if (st.empty() || st.top() < 0 || st.top() < -num)
                    st.push(num);
                if (!st.empty() && st.top() ==  -num )
                    st.pop();
            }
            else 
                st.push(num);
        }
        while (!st.empty()){
            ans.push_back(st.top()) , st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};