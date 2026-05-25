class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long mul = 1;
        stack<int> st;
        vector<int> ans;
        while (n){
            if (n%10 != 0)
                st.push((n%10)*mul);
             n/=10 , mul*=10;
        }
        while (!st.empty())
            ans.push_back(st.top()) , st.pop();

        return ans;
    }
};