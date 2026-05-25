class Solution {
    bool vis[1005];
    void dfs(int node , vector<vector<int>>& rooms){
        vis[node] = 1;
        for(auto& elem : rooms[node])
            if (!vis[elem])
                dfs(elem , rooms);
        return;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs( 0 , rooms);
        for (int i = 0 ; i < rooms.size() ; i++){
            if(!vis[i])
                return false;
        }
        return true;
    }
};