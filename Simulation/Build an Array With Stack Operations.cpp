class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for (int i = 1 , j = 0; i <= n ; i++){
            ans.push_back("Push");
            if (j == target.size() - 1 && target.back() == i)
                return ans;
            if (target[j] != i)
                ans.push_back("Pop");
            else j++;
        }
        return ans;
    }
};