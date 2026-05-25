class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <vector<int>> ans (n - 2 , vector <int> (n-2 , 0));
        for (int i = 1; i < n - 1;i++)
        {
            for (int j = 1; j < n - 1;j++)
            {
                int maximum = 0;
                for (int k = i - 1 ; k < i+2;k++)
                {
                    for (int m = j - 1; m < j+2;m++)
                    {
                        maximum = max(maximum , grid[k][m]);
                    }
                }
                ans[i-1][j-1] = maximum;
            }
        }
        return ans;
        
    }
};