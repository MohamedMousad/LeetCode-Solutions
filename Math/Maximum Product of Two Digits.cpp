class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10 , false);
        while(n){
            freq[(n%10)]++;
            n/=10;
        }
        int take = 0 , ans = 1;
        for (int i = 9 ; i >= 0 ; i--){
            while (freq[i] > 0 && take < 2){
                ans*=i;
                freq[i]--;
                take++;
            }
            if (take == 2)
                return ans;
        }
        return ans;
    }
};