class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, curr = 5;
        while (curr <= n ){
            ans+=(n/curr);
            curr*=5;
        }
        return ans;
    }
};