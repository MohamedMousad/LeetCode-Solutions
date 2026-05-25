class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size() - 1 , ans = 0;
        while ( l < r){
            ans = max( (r - l)*min(height[r] , height[l]) , ans);
            (height[r] >= height[l] ? l++ : r--);
        }
        return ans;
    }
};