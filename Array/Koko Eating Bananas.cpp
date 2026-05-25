class Solution {
    bool good(vector<int>& piles, int h , long long mid){
        long long cnt = 0 ;
        for (int i = 0 ; i < piles.size() ; i++)
            cnt+=(piles[i]/mid + (piles[i]%mid != 0));
        return cnt <= h;
    }
    int BS(vector<int>& piles, int h){
        int l = 1 , r = 1e9 , ans = 1;
        while (l <= r ) {
            long long mid = l + ((r-l)>>1);
            if (good(piles , h , mid))
                r = mid - 1 , ans = mid;
            else 
                l = mid + 1;
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return BS(piles , h);
    }
};