class AllOne {
    unordered_set<string> freq[50005];  
    unordered_map<string,int> mp;
    int mx = 0 , mn = 0;  
public:
    AllOne() {
    }

    void inc(string key) {
        int score = mp[key];
        mp[key]++;
        if (score != 0)
            freq[score].erase(key);
        freq[score+1].insert(key);
        mx = max(mx, score+1);
        mn = min(mn , score+1);
        if (mn == score && freq[score].empty())
            mn++;
    }

    void dec(string key) {
        int score = mp[key];
        freq[score].erase(key);
        if (score == mx && freq[score].empty())
            mx--;
        mp[key]-- , score--;
        if (score != 0)
            freq[score].insert(key) , mn = min(mn , score);
        mx = max(score , mx);
        if (freq[mn].empty()){
            for (int i = 0 ; i <= mx ; i++){
                if (!freq[i].empty()){
                    mn = i;
                    return;
                }
            }
            mn = 0;
        }
    }
    
    string getMaxKey() {
        return (mx == 0 ? "" : (*freq[mx].begin()));
    }
    
    string getMinKey() {
        return (mn == 0 ? "" : (*freq[mn].begin()));
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */