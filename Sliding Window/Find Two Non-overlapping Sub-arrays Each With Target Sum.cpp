class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> best(arr.size() + 5, 1e7);
        int res = 1e7 , sum = 0;
        for (int l = 0 , r = 0 ; r < arr.size() ; r++){
            sum+=arr[r];
            while (sum > target){
                sum-=arr[l++];
            }
            if (sum == target){
                best[r] = r - l + 1;
                if (l >  0)
                    res = min(res , best[r] + best[l-1]);
            }
            if (r > 0 ){
                best[r] = min(best[r-1] , best[r]);
            }
        }
        return (res < 1e7 ? res : -1);
    }
};