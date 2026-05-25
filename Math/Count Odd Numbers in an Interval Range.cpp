class Solution {
public:
    int countOdds(int low, int high) {
        low = max(low-1 , 0);
        int ans = (high/2 + (high % 2 != 0) ) - (low/2 + (low % 2 != 0) );
        return ans;
    }
};