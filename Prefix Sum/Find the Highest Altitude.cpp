class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int ans = 0,  curr = 0;
        for (int i = 0 ; i < gain.size() ; i++){
            curr = curr + gain[i];
            ans = max(curr , ans);
        }
        return ans;
    }
};