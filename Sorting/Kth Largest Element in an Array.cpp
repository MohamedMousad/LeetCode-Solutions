class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto& num : nums)
            pq.push(num);
        int i = 0 , ans = 0; 
        while (!pq.empty() && i < k){
            ans = pq.top();
            pq.pop();
            i++;
        }
        return ans;
    }
};