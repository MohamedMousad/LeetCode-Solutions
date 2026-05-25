class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto lambda = [&](const pair<int,int>& x ,const pair<int,int>& y){
            return x.first + x.second < y.first + y.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(lambda)> pq(lambda);
        for (int i = 0 ; i < nums1.size(); i++){
            for (int j = 0 ; j < nums2.size() && (pq.size() < k ||( nums1[i] + nums2[j] < pq.top().first + pq.top().second)); j++){
                pq.push({nums1[i] , nums2[j]});
                if (pq.size() > k) pq.pop();
            }
       }
        vector<vector<int>> ans;
        while (!pq.empty()){
            ans.push_back({pq.top().first , pq.top().second}) , pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};