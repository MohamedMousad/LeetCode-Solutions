class Solution {
    bool vis[10][10] = {};
    int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    vector<int> t ;
    bool dfs(int i , int j , int cnt){
        if (i < 0 || j < 0 || j > 7 || i > 7)
            return false;
        vis[i][j] = true;
        if (i == t[0] && j == t[1])
            return cnt%2 == 0;
        bool ch = false;
        for (int k = 0 ; k < 8 ; k++ ){
            int nx = dx[k] + i , ny = dy[k]  + j;
            if (!(nx < 0 || ny < 0 || ny > 7 || nx > 7)  && !vis[nx][ny]){
                ch|=dfs(nx  ,ny , cnt+1);
            }
        }
        return ch;
    }
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        t = target;
        return dfs(start[0] , start[1] , 0);
    }
};