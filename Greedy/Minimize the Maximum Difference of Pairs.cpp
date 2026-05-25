class Solution {
public:
    bool good (vector<int>& nums , int p , long long mid){
        long long mx = 2e9 , cnt = 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++){
            if (abs(nums[i] - nums[i+1]) <= mid ){
                cnt++;
                i++;
            }
            if (cnt >= p) return true;
        }
        return cnt >= p ;
    }
    long long BS(vector<int>& nums , int p){
        long long l = 0 , r = 2e9 , mid = 0 , ans = 0;
            while (l<=r){
                mid =  l + (r-l)/2;
                if (good(nums ,p , mid)){
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid+1;
                }
            }
        return ans;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin() , nums.end());
        return BS(nums , p);
    }
};