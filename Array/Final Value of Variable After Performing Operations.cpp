class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        short ans = 0;
        for (int i = 0 ; i < operations.size() ; i++){
            if (operations[i].contains('+')) ans++;
            else ans--;
        }
        return ans;
    }
};