class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<short>> freq(32 , vector<short>(10 , 0)) ;
        vector<short>curr(10 , 0);
        for(int i = 0 ; i < 31 ; i++){
            int num = (1<<i);
            while (num){
                freq[i][num%10]++;
                num/=10;
            }
        }

        while (n) curr[n%10]++ , n/=10;

        for(int i = 0 ; i < 32 ; i++)
            if (curr == freq[i]) return true;
    
        return false;
    }
};