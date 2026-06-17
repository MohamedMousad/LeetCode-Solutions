class Solution {
    vector<bitset<100005>> route;
    bool vis[501] = {};
    int n = 0;
    int bfs( int source, int target){
        if (source == target)
            return 0;
        queue<pair<int,int>> q;
        for (int i = 0 ; i < route.size(); i++){
            if (route[i][source])
                q.emplace(i , 1)  , vis[i] = true;
        }
        while(!q.empty()){
            auto [curr , cost] = q.front();
            q.pop();
            if (route[curr][target])
                return cost;
            for (int i = 0 ; i < route.size(); i++){
                if (!vis[i]){
                    if ((route[curr] & route[i]).any())
                        q.emplace(i , cost + 1)  , vis[i] = true;
                }
            }
        }
        return -1;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        route.resize(routes.size());
        for (int i = 0 ;i < routes.size() ; i++){
            for (int j = 0 ; j < routes[i].size() ; j++){
                route[i][routes[i][j]] = 1;
            }
        }
        return bfs (source , target);
    }
};