class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size() , req = n - 1 , ans = 0;
        vector<pair<int,int>> a (n);
        for (int i = 0 ; i < n ; i++){
            for (int j = i ; j < n ; j++){
                int cnt = 0 ;
                for (int k  = n-1 ; k >= 0 && grid[j][k] == 0 ; k-- , cnt++){
                }
                if (j == n-1 && cnt < req)
                    return -1;
                if (cnt >= req){
                    ans+=(j - i);
                    req--;
                    while (j > i){
                        grid[j].swap(grid[j-1]);
                        j--;
                    }
                    break;
                }
            }
       } 
       return ans;
    }
};