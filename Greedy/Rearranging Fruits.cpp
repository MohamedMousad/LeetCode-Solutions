class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,pair<int,int>> mp;
        vector<int> needed1 , needed2;
        int mn = INT_MAX;
        for (int i = 0 ; i < basket1.size() ; i++)
            mp[basket1[i]].first++ , mp[basket2[i]].second++ , mn = min({basket2[i] , basket1[i] , mn});
        for (auto& elem : mp){
            if ((elem.second.first + elem.second.second)%2 == 1) return -1;
            int first = elem.second.first , second = elem.second.second;
            while (first > second)
                needed2.push_back(elem.first) , first-- , second++;
            while (first < second)
                needed1.push_back(elem.first) , first++ , second--;
        }
        sort(needed1.begin() , needed1.end()) , sort(needed2.begin() , needed2.end());
        long long ans = 0 ;
        for (int l = 0 , r = 0 ; l + r < needed1.size();){
            if ((mn<<1) <= min(needed1[l] ,  needed2[r])) {
                ans+=((mn<<1)*(needed1.size() - (l+r)));
                return ans ;
            }
            ans+=min(needed1[l] ,  needed2[r]);
            if (needed1[l] < needed2[r]) l++;
            else r++;
        }
        return ans;
    }
};