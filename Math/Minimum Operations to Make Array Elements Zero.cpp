class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto& query : queries){
            long long sum = 0 , l = query[0] , r = query[1] , end = 1 , add = 0 , prev = 0;
            while (end <= l) {
                end*=4LL;
                add++;
            }
            prev = end/4;
            while (prev <= r ){
                end = min(r + 1LL , end);
                prev = max(l , prev);
                sum += (end - prev)*(add++);
                prev = end;
                end = min(r + 1LL , end*4LL);
            }
            ans+=(sum/2 + (sum%2 != 0));
        }
        return ans;
    }
};