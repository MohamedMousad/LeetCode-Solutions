class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,pair<int,int>> mp;
        for (int i= 0 ; i < nums1.size(); i++){
            mp[nums1[i]].first++;
        } 
        vector<int> res;
        for (int i = 0 ; i < nums2.size(); i++){
            mp[nums2[i]].second++;
        }
        for (auto elem : mp){
            int mn = min(elem.second.first , elem.second.second);
            while(mn--){
                res.push_back(elem.first);
            }
        }
        return res;
    }
};
