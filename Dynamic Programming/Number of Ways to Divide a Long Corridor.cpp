class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 1;
        int s = 0 , s2= 0  , mul = 0 , mod = 1e9+7;
        for(int i = 0 ; i < corridor.size() ; i++){
            if (corridor[i] == 'S')
                s++ , s2++;
            if (s == 2 )
                mul++;
            else if( s > 2 )
                ans*=mul , mul = 0 , ans%=mod , s = 1;
        }
        if (s2&1 || s2 == 0) ans = 0;
        return ans;
    }
};