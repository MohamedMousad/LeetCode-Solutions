public class Solution {
    public int DigitFrequencyScore(int n) {
        int ans = 0;
        while (n > 0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
}