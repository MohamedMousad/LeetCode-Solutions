class Twitter {
    vector<int> userPosts[505] = {};
    vector<int> posts;
    unordered_set<int> adj[505] = {};
    int timestamp = 0;
public:
    Twitter() {
        for (int i = 0 ; i < 505 ; i++)
            adj[i].insert(i);
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back(timestamp);
        posts.push_back({tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<int , vector<int> , greater<int>>pq ;
        for (auto& fr :adj[userId]){
            for (auto& postTime : userPosts[fr]){
                if (pq.size() < 10 || pq.top() < postTime ){
                    pq.push(postTime);
                    if (pq.size() > 10)
                        pq.pop();
                }
            }
        } 
        vector<int> res;
        while (!pq.empty()){
            res.push_back(posts[pq.top()]);
            pq.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        adj[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if ( adj[followerId].count(followeeId) == 0)
            return;
        adj[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */