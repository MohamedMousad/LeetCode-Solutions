class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0 ; i < grid.size() ; i++){
            sort(grid[i].begin() , grid[i].end());
            ans+= (upper_bound(grid[i].begin() , grid[i].end() , -1) - grid[i].begin());
        }
        return ans;
    }
};