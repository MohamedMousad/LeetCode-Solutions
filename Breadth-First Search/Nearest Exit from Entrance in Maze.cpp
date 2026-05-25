class Solution {
    int dx[4] = {-1 , 1 , 0 , 0};
    int dy[4] = {0 , 0 , -1 , 1};
    bool vis[101][101] = {};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size() , n = maze[0].size();
        queue<pair<pair<int,int> , int>> q;
        q.push({{entrance[0] , entrance[1] }, 0});
        vis[entrance[0]][entrance[1]] = 1;
        while (!q.empty()){
            pair<pair<int,int> , int> front = q.front();
            q.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nx = dx[i] + front.first.first , ny = dy[i] + front.first.second;
                if (nx < m && nx >= 0 && ny < n && ny >= 0 && maze[nx][ny] != '+' &&  !vis[nx][ny] ){
                    if (nx == 0 || ny == 0 || nx == m-1 || ny == n-1)
                        return front.second + 1;
                    q.push({{nx , ny} , front.second + 1}) , vis[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};