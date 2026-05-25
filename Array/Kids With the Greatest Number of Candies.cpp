class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0 ;
        vector<bool> res(candies.size());
        for (auto& num : candies)
            mx = max(mx , num);
        for (int i = 0 ; i < candies.size() ; i++){
            if (candies[i] + extraCandies >= mx)
                res[i] = true;
        }
        return res;
    }
};