class FindSumPairs {
 public:
     unordered_map<int,int> a;
     unordered_map<int,int> b;
     vector<int> nums1;
     vector<int> nums2;
     FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2){
         for (int i = 0 ; i < nums1.size() ; i++) {
             a[nums1[i]]++;
         }
         for (int i = 0 ; i < nums2.size() ; i++) {
             b[nums2[i]]++;
         }
     }
     void add(int index, int val) {
         int temp = nums2[index];
         nums2[index] += val;
         b[temp + val]++;
         b[temp]--;
         if (b[temp] == 0) b.erase(b[temp]);
     }
     int count(int tot) {
         int sum = 0 ;
         for (auto& num : a) {
             if (tot >= num.first ) {
                 if (b.find(tot - num.first) != b.end())
                    sum+=(b[tot-num.first]*num.second);
             }
         }
         return sum;
     }
 };

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */