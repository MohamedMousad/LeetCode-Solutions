class Solution {
    unordered_map<string , int> videos;
    bool vis[101] = {};
    vector<string> res;
    int goal;
    void bfs(int node , vector<vector<string>>& watchedVideos ,  vector<vector<int>>& friends ){
        queue<pair<int,int>> q;
        q.push({node , 0});
        vis[node] = true;
        while (!q.empty()){
            auto [curr , level] = q.front();
            q.pop();
            vis[curr] = true;
            for (auto& fr : friends[curr]){
                if (!vis[fr]){
                    vis[fr] = true;
                    q.push({fr , level+1});
                }
            }
            if (level == goal){
                for (auto& video : watchedVideos[curr]){
                    if (videos[video] == 0)
                        res.push_back(video);
                    videos[video]++;
                }
            }
        }
    }
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        goal = level;
        bfs(id , watchedVideos , friends);
        sort(res.begin() , res.end() , [&](string& a , string& b ){
            if (videos[a] == videos[b])
                return a < b;
            return videos[a] < videos[b];
        });
        return res;
    }
};