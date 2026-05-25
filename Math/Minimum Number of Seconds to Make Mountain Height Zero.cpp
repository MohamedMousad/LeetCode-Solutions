class Solution {
    bool good(int mountainHeight, vector<int>& workerTimes , long long mid){
        long long cnt = 0;
        for (int i = 0 ;i < workerTimes.size() ; i++){
            long double remain = (long double)(mid)/(workerTimes[i]);
            long long curr = 1;
            long long max_k = (sqrt(1.0 + 8.0 * remain) - 1.0) / 2.0;
            cnt+=max_k;
            if (cnt >= mountainHeight)
                return true;
        }
        return cnt >= mountainHeight;
    }
    long long BS(int mountainHeight, vector<int>& workerTimes){
        long long l = 1 , r = 1 , ans = -1 , mid = 0;
        while(!good(mountainHeight , workerTimes , r))
            r<<=1;
        while (l <= r ){
            mid = l + (r - l)/2;
            if (good(mountainHeight , workerTimes , mid))
                ans = mid , r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        return BS(mountainHeight , workerTimes);
    }
};