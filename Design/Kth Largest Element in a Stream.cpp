class KthLargest {
    priority_queue<int , vector<int> , greater<int>> pq;
    int cap = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for (int i = 0; i <nums.size() ; i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > cap)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */