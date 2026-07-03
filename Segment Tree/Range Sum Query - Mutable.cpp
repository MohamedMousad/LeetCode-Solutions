class NumArray {
    bool excl = 0; 
    const int N = 1e5;
    int n; int t[200005] = {};
    void build(vector<int>& nums){
        n = nums.size();
        for (int i = n ; i < n*2 ; i++)
            t[i] = nums[i-n];
        for (int i = n - 1 ; i > 0 ; i--)
            t[i] = t[i<<1] + t[i<<1 | 1];
    }

    void modify(int p , int val){
        for (t[p+=n] = val ; p > 1 ; p>>=1)
            t[p>>1] = t[p] + t[p^1];
    }

    int query(int l , int r){
        int res = 0;
        if (!excl) r++;
        for (l+=n , r+=n ; l < r ; l>>=1 , r>>=1 ){
            if (l&1) res+=t[l++];
            if (r&1) res+=t[--r];
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        build(nums);
    }
    void update(int index, int val) {
        modify(index , val);
    }
    
    int sumRange(int left, int right) {
        return query(left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */