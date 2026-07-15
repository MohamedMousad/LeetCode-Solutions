class Solution {
    int dp[303][303][2] = {};
    int mx = 0;
    int rec(int x , int y , bool hor , vector<vector<char>>& matrix){
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())
            return 0;
        int& ret = dp[x][y][hor];
        if (~ret)
            return ret;
        if (matrix[x][y] == '0')
            return ret = 0;
        if (hor)
            return ret = rec(x, y+1 , hor , matrix) + 1;
        return ret = rec(x + 1, y , hor , matrix) + 1;
    }
    int get_max(int x, int y,vector<vector<char>>& matrix){
        if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())
            return 0;
        int curr = min(dp[x][y][0] , dp[x][y][1]) , nxt = get_max(x+1 , y+1 , matrix);
        if (curr > nxt ){
            mx = max(mx , nxt+1);
            return nxt + 1;
        }
        else{
            mx = max(mx , curr);
            return curr;
        }
    }
    void debug(vector<vector<char>>& matrix) {
        for (int i = 0 ; i < matrix.size(); i++) {
            for (int j = 0 ; j < matrix[0].size(); j++) {
                cout << dp[i][j][0] << "|" << dp[i][j][1] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
        for (int i = 0 ; i < matrix.size(); i++) {
            for (int j = 0 ; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;
        cout << endl;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp , -1 , sizeof dp);
        for (int i = 0 ; i < matrix.size() ; i++){
            for (int j = 0 ; j < matrix[0].size() ; j++){
                if (dp[i][j][0] == -1)
                    rec(i , j , 0 , matrix);
                if (dp[i][j][1] == -1)
                    rec(i , j , 1 , matrix);
            }
        }
        // debug(matrix);
        for (int i = 0 ; i < matrix.size() ; i++)
            get_max( i , 0 , matrix);
        for (int i = 0 ; i < matrix[0].size() ; i++)
            get_max( 0 , i , matrix);
        return mx*mx;
    }
};