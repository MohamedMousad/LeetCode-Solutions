class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; 
        st.push_back(nums[0]);
        for (int i = 1 ; i < nums.size() ; i++){
            long long other = nums[i];
            int g = __gcd(st.back() ,(int) other);
            while (g > 1 && !st.empty() ){
                other = st.back() / g * other; 
                st.pop_back();
                if (!st.empty())
                    g = __gcd((int)other , st.back());
            }
            st.push_back(other);
        }
        return st;
    }
};