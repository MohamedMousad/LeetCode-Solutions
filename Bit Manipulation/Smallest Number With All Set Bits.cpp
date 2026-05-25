class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0 , mul = 0;
        while (ans < n){
            ans+=(1<<mul);
            mul++;
        }
        return ans;
    }
};