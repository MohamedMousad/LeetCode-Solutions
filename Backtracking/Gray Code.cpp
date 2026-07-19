class Solution {
    bool vis[100005] = {};
    vector<int> adj[100005] = {};
    vector<int> ans;
    int N;
    bool rec(int num = 0){
        ans.push_back(num);
        vis[num] = true;
        if (ans.size() == N)
            return true;
        for (auto& elem : adj[num]){
            bool ch = false;
            if (!vis[elem])
                ch = rec(elem);
            if (ch)
                return true; 
        }
        vis[num] = false;
        ans.pop_back();
        return false;
    }

public:
    vector<int> grayCode(int n) {
        // build connections
        for (int i = 0 ; i < (1<<n) ; i++){
            for (int num = i , bit = 1 ; bit < (1<<16)  ; bit<<=1){
                num^=bit;
                if (num < (1<<n))
                    adj[i].push_back(num);
                num^=bit;
            }
        }
        N = (1LL<<n);
        rec();
        return ans;
    }
};