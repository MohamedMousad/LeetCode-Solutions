class Solution {
    void fill( int i , int j , int ch ,  vector<vector<int>>& vis){
        for (int y = 0 ; y < vis.size(); y++) vis[i][y]+=ch , vis[y][j] +=ch;
        int x = i ,y = j;
        while (x >= 0 && y >= 0 && x < vis.size() && y < vis.size()) vis[x][y] += ch , x++ , y++;
        x = i , y  = j;
        while (x >= 0 && y >= 0 && x < vis.size() && y < vis.size()) vis[x][y] += ch , x-- , y++;
        x = i , y  = j;
        while (x >= 0 && y >= 0 && x < vis.size() && y < vis.size()) vis[x][y] += ch , x-- , y--;
        x = i , y  = j;
        while (x >= 0 && y >= 0 && x < vis.size() && y < vis.size()) vis[x][y] += ch , x++ , y--;
    }
    int rec(int i , int j , int count , vector<vector<int>>& vis ){
        if (i >= vis.size() || j >= vis.size()){
            if (count == 0)
                return 1;
            return 0;
        }
        if (count == 0) return 1;
        int ch = 0;
        if ( vis[i][j] == 0){
            fill(i , j , 1 ,vis);
            if (i < vis.size() - 1)
                ch+=(rec(i+1 , j , count - 1, vis));
            else 
                ch+=(rec(0 , j+1 , count - 1 , vis));
            fill(i , j , -1 , vis);
        }
        if (i < vis.size() - 1)
            ch+=(rec(i+1 , j , count , vis));
        else 
            ch+=(rec(0 , j+1 , count , vis));
        return ch;
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> vis(n , vector<int>(n  , 0));
        return rec( 0 ,  0 , n ,  vis);
    }
};