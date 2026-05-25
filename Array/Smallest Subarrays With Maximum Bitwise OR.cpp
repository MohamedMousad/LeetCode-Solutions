class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> freq(32) , maxes(nums.size()) , ans(nums.size());
        
        for (int i = nums.size()-1 ; i >= 0 ; i--){
            if (i == nums.size()-1)
                maxes[i] = nums[i];
            else 
                maxes[i] = maxes[i+1]|nums[i];
        }
        int sum_or = 0;
        for (int l = 0  , r = 0; l < nums.size() ; l++){
            while (r < nums.size() && sum_or < maxes[l]){
                for (int j = 0 ; j < 32 ; j++){
                    if (nums[r] & (1ll<<j)){
                        if (freq[j] == 0)
                            sum_or+=(1ll<<j);
                        freq[j]++;
                    }
                }
                r++;
            }
            ans[l]= (r-l);
            if (r == l) {
                ans[l] = 1ll;
                r = l+1;
                continue;
            }
            else {
                for (int j = 0 ; j < 32 ; j++){
                    if ((nums[l] & (1ll << j))){
                        if (freq[j] == 1ll)
                            sum_or-=(1ll << j);
                        freq[j]--;
                    }
                }
            }
        }
        return ans;
    }
};