class Solution {
    int dx[4] = {1  , -1, 0 , 0};
    int dy[4] = {0 , 0 , 1 , -1};
    int vis[51][51] = {};
    int BS(int n ,vector<vector<int>>& grid){
        int l = 0 , r = n*n , ans = n*n , counter = 0;
        while (l <= r ){
            int mid = (l + ((r-l)>>1));
            if (bfs(0,0,mid , n ,grid , counter))
                r = mid -1 , ans = mid;
            else
                l = mid + 1;
            counter++;
        }
        return ans;
    }
    bool bfs(int x , int y , int mx,  int n , vector<vector<int>>& grid , int& counter){
        queue<pair<pair<int,int> , int>> nodes;
        nodes.push({{x , y} , grid[x][y]});
        vis[x][y] = 1;
        bool good= false;
        while (!nodes.empty()){
            auto front = nodes.front();
            nodes.pop();
            for (int i = 0 ; i < 4 ; i++){
                int nx = front.first.first + dx[i] , ny = front.first.second + dy[i];
                if (nx >= 0 && ny >= 0 && nx <= n-1 && ny <= n-1 && vis[nx][ny] <= counter && max(grid[nx][ny] , front.second) <= mx){
                    vis[nx][ny]++;
                    nodes.push({{nx , ny} , (grid[nx][ny] < front.second ? front.second : grid[nx][ny])});
                }
            }
            if (front.first.first == n-1 && front.first.second == n-1 ) good = true;
        }
        return good;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        return BS(n , grid);
    }
};