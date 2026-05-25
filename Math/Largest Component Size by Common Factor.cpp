class Solution {
    int par[100005] = {};
    int size[100005] = {};
    int find(int j ){
        if (par[j] == j) return j;
        return par[j] = find(par[j]);
    }
    void merge(int i , int j){
        int first = find(i) , sec = find(j);
        if (first == sec)   
            return;
        if (size[first] < size[sec])
            swap(first , sec);
        par[sec] = par[first];
        size[first]+=size[sec];
    }
public:
    int largestComponentSize(vector<int>& nums) {
        unordered_set<int> remain;
        unordered_map<int,int> group;
        vector<bool> isPrime(100005,true);
        for (int i = 0; i < nums.size() ; i++){
            par[nums[i]] = nums[i];
            size[nums[i]] = 1;
            remain.insert(nums[i]);
        }
        for (long long i = 2 ; i < 1e5 + 5 ; i++) {
            int last = -1;
            if (remain.count(i) && last == -1)
                last = i;
            if (isPrime[i]) {
                for(long long j = i*2 ; j < 1e5 + 5 ; j+=i)
                {
                    isPrime[j] = false;
                    if (last != -1 && remain.count(j) != 0)
                        merge(last , j);
                    if (remain.count(j) && last == -1)
                        last = j;
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < nums.size() ; i++)
            group[find(nums[i])]++ , mx = max(mx ,group[find(nums[i])]);
        return mx;
    }
};