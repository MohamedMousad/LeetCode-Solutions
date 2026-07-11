class Solution {
    class segTree{
        public:
        bool excl = 0; 
        int n; vector<int>t = {};
        int target = 0;
        int sz = 1;
        segTree(vector<int>& nums){
            n = nums.size();
            while (sz < n) sz<<=1;
            t.resize(2*sz);
            for (int i = sz ; i < sz + n ; i++)
                t[i] = nums[i-sz];
            for (int i = sz - 1 ; i > 0 ; i--)
                t[i] = max(t[i<<1] , t[i<<1 | 1]);
        }

        void modify(int p , int val){
            for (t[p+=n] = val ; p > 1 ; p>>=1)
                t[p>>1] = t[p] + t[p^1];
        }
        int left(int i){
            return i<<1;
        }
        int right (int i ){
            return (i<<1) + 1;
        }
        bool lead(int i ){
            while ((i<<1) + 1 < 2*sz){
                i = (i<<1) + 1;
            }
            return i > (target+sz);
        }
        int query(int curr , int mx){
            if (t[curr] <= mx)
                return -1;
            if (curr >= sz && curr - sz > target)
                return curr - sz ;
            int ch = -1;
            if (lead(left(curr)))
                ch = query( left(curr) , mx);
            if (~ch)
                return ch;
            if (lead(right(curr)))
                ch = query(right(curr) , mx);
            return ch;
        }
    };
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        auto seg = new segTree(heights);
        vector<int> res(queries.size() , -1);
        for (int i = 0; i < queries.size() ; i++){
            int l = queries[i][0] , r = queries[i][1];
            if (l > r ) swap(l , r);
            if (heights[r] > heights[l] || r == l){
                res[i] = r;
                continue;
            }
            seg->target = r;
            int ans = seg->query(1, heights[l]);
            res[i] = ans;
        }
        return res;
    }
};