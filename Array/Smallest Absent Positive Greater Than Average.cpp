class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg = 0;
        int freq[105] = {};
        for (int i = 0 ;  i < nums.size() ; i++){
            avg+=nums[i];
            if (nums[i] > 0)
                freq[nums[i]]++;
        }
        avg/=((int)(nums.size())) ; avg++;
        for (int i = max(avg , 1) ; i < 105 ; i++){
            if (freq[i] == 0) return i;
        }
        return avg;
    }
};