class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mnrow  = INT_MAX , mxrow = -INT_MAX , mncol = INT_MAX , mxcol = -INT_MAX;
        bool flag = 0;
        for (int i = 0 ; i < grid.size() ; i++){
            for (int j = 0 ; j < grid[0].size() ; j++){
                if (grid[i][j] == 1){
                    mnrow = min(i , mnrow);
                    mncol = min(j , mncol);
                    mxrow = max(i , mxrow);
                    mxcol = max(j , mxcol);
                }
            }   
        }
        return (mxrow - mnrow + 1LL)*(mxcol - mncol + 1LL);
    }
};