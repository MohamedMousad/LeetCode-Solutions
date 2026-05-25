class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int l = 0 , r = costs.size() - 1;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> buffer;
        while (l < min( candidates , (int)(costs.size()) ))
            buffer.push({costs[l] , l}) , l++;
        while (r >= l && candidates){
            buffer.push({costs[r] , r}) ;
            candidates-- , r--;
        }
        long long ans = 0;
        while (k){
            auto cost = buffer.top();
            buffer.pop();
            ans += cost.first;
            if (cost.second < l && l <= r)
                buffer.push({costs[l] , l}) , l++;
            else if (cost.second > r && l <= r)
                buffer.push({costs[r] , r}) , r--;
            k--;
        }
        return ans;
    }
};