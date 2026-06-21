class Solution {
    vector<vector<int>> res;
    int dx[4] = {-1 , 1 , 0 , 0 };
    int dy[4] = {0 , 0 , -1 , 1};
    queue<pair< pair<int,int> , int>> cells; 
    int bfs (vector<vector<int>>& isWater){
        int ans = 0;
        while (!cells.empty()){
            auto front = cells.front();
            cells.pop();
            int x = front.first.first , y = front.first.second , cost = front.second;
            for (int k = 0 ; k < 4 ; k++){
                int nx = x + dx[k] , ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < isWater.size() && ny < isWater[0].size() && isWater[nx][ny] == 0){
                    ans = cost + 1;
                    res[nx][ny] = cost + 1;
                    cells.push({{nx , ny} , cost + 1}) , isWater[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int ans = 0;
        res.resize(isWater.size());
        for (auto& i : res)
            i.assign(isWater[0].size() , 0);
        for (int i = 0 ; i < isWater.size() ; i++){
            for (int j = 0 ; j < isWater[i].size() ; j++){
                if (isWater[i][j] == 1 ){
                    cells.push({{i , j} , 0});
                }
            }
        }
        bfs(isWater);
        return res;
    }
};