class Solution {
    vector<vector<int>> res;
    int dx[4] = {-1 , 1 , 0 , 0 };
    int dy[4] = {0 , 0 , -1 , 1};
    queue<pair< pair<int,int> , int>> cells; 
    void bfs (vector<vector<int>>& isWater){
        while (!cells.empty()){
            auto front = cells.front();
            cells.pop();
            int x = front.first.first , y = front.first.second , cost = front.second;
            for (int k = 0 ; k < 4 ; k++){
                int nx = x + dx[k] , ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < isWater.size() && ny < isWater[0].size() && isWater[nx][ny] != 0){
                    res[nx][ny] = cost + 1;
                    isWater[nx][ny] = 0;
                    cells.push({{nx , ny} , cost + 1});
                }
            }
        }
        return ;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int ans = 0;
        res.resize(mat.size());
        for (auto& i : res)
            i.assign(mat[0].size() , 0);
        for (int i = 0 ; i < mat.size() ; i++){
            for (int j = 0 ; j < mat[i].size() ; j++){
                if (mat[i][j] == 0 ){
                    cells.push({{i , j} , 0});
                }
            }
        }
        bfs(mat);
        return res;
    }
};