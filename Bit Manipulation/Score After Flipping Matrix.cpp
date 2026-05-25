class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = !grid[i][j];
            }
        }
    }
    int zeros = 0, ones = 0, sum = 0;
    for (int j = 0; j < n; j++)
    {
        zeros = 0, ones = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[i][j] == 0)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }
        if (ones < zeros)
        {
            for (int i = 0; i < m; i++)
            {
                grid[i][j] = !grid[i][j];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
                sum += pow(2, n - j - 1);
        }
    }
        return sum;
    }
};