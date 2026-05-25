class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> nums;
        for (int i = 0 ; i < nums1.size() ; i++)
            nums.emplace_back(nums1[i] , nums2[i]);

        sort(nums.begin() , nums.end() , [&](pair<int,int>& a , pair<int,int>& b){
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.second;
        });

        long long ans = 0 , sum = 0;
        priority_queue<int , vector<int> , greater<int>> k_elems;
        for (int i = nums.size() - 1 ; i >= 0;i--){
            long long mul = nums[i].second;
            k_elems.push(nums[i].first); 
            sum+=nums[i].first;
            if (k_elems.size() < k ) continue;
            if (k_elems.size() > k ) sum-=k_elems.top() , k_elems.pop();
            ans = max(ans , sum*mul);
        }
        return ans;
    }
};