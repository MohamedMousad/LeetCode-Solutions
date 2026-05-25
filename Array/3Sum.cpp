class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<pair<pair<int,int> , int>> st;
        for (int i = 0 ; i < nums.size() ; i++){
            for (int j = i + 1 ; j < nums.size() ; j++){
                auto it = lower_bound(nums.begin() + j + 1 , nums.end() , - (nums[i] + nums[j]));
                if (it != nums.end() && *it ==  - (nums[i] + nums[j]) ){
                    st.insert({ {nums[i] , nums[j]} , *it});
                }
            }
        }
        vector<vector<int>> ans ;
        for (auto& elem : st){
            vector<int> a = {elem.first.first , elem.first.second , elem.second};
            ans.push_back(a);
        }
        return ans;
    }
};