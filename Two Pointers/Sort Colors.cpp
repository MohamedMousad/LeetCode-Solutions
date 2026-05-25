class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3] = {};
        for (int& num : nums) freq[num]++;
        for (int i = 0 , j = 0 ; i < 3 ; i++) while (freq[i]--) nums[j++] = i;
    }
};