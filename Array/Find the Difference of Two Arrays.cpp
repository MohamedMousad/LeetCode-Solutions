class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int freq1[2050] = {}, freq2[2050] = {};
        for (int i = 0 ; i < nums1.size(); i++)
            freq1[nums1[i]+1010]++;
        for (int i = 0 ; i < nums2.size(); i++)
            freq2[nums2[i]+1010]++;
        vector<vector<int>> ans(2);
         for (int i = 0 ; i < nums1.size(); i++){
            if (freq2[nums1[i]+1010] == 0 && freq1[nums1[i]+1010] != -1)
                ans[0].push_back(nums1[i]) , freq1[nums1[i]+1010] = -1 ;
         }
         for (int i = 0 ; i < nums2.size(); i++){
            if (freq1[nums2[i]+1010] == 0 && freq2[nums2[i]+1010] != -1)
                ans[1].push_back(nums2[i]) , freq2[nums2[i]+1010] = -1;
         }
        return ans;
    }
};