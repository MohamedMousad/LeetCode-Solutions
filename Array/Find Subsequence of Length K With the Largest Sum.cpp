class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int,int>> nums2(nums.size());
        priority_queue<int , vector<int> , greater<int>> pq; 
        for (int i = 0 ; i < nums.size(); i++){
            nums2[i].first = nums[i];
            nums2[i].second = i;
        }
        sort(nums2.begin() , nums2.end());
        for (int i = nums2.size() - k ; i < nums2.size() ; i++){
            pq.push(nums2[i].second);
        }
        while (!pq.empty()){
            ans.push_back(nums[pq.top()]);
            pq.pop();
        }
        return ans;
    }
};