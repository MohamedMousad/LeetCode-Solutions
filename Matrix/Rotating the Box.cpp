class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size() , m = boxGrid[0].size();
        vector<vector<char>> ans(m , vector<char>(n));
        for (int i = 0 ; i < n; i++){
            int cnt = 0 , last_processed = 0;
            for (int j  = 0 ; j < m ; j++){
                if (boxGrid[i][j] == '*'){
                    int k = j;
                    ans[k][i] = '*';
                    k--;
                    while (k >= 0 && cnt > 0)
                        ans[k][i] = '#' , cnt-- , k--;
                    while (k >= 0 && ans[k][i] != '*')
                        ans[k][i] = '.' , k--;
                }
                else if (boxGrid[i][j] == '#')
                    cnt++;
            }
            int k = m - 1;
            while (k >= 0 && cnt > 0)
                ans[k][i] = '#' , cnt-- , k--;
            while (k >= 0 && ans[k][i] != '*')
                ans[k][i] = '.' , k--;
        }
        for (int i = 0 ; i < m; i++){
            reverse(ans[i].begin() , ans[i].end());
        }
        return ans;
    }
};