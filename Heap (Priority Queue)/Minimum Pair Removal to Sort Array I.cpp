class Solution {
public:
    bool isNonDescending(vector<int> &nums){
        for(int i = 1;i<nums.size();i++){
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!isNonDescending(nums)){
            int mini = 0;
            for(int i = 1;i<nums.size()-1;i++){
                if(nums[i] + nums[i+1] < nums[mini] + nums[mini+1])
                    mini = i;
            }
            nums.insert(nums.begin() + mini, nums[mini] + nums[mini+1]);
            nums.erase(nums.begin() + mini+1, nums.begin() + mini + 3);
            cnt++;
        }
        return cnt;
    }
};