class LFUCache {
    int mx = 0 , curr_size = 0 , counter = 0;
    unordered_map<int,int> values;
    // key => use_counter - counter
    unordered_map<int,pair<int,int>> exist;
    // freq - key  - counter
    unordered_map<int , queue<pair<int,int>>> freq_q;
    // freq
    unordered_map<int,int> nxt_freq;
    int mn_freq = 1;
public:
    LFUCache(int capacity) {
        mx = capacity;
    }
    
    int get(int key) {
        if (exist.count(key) == 0)
            return -1;
        if ( exist[key].second != -1){
            int freq = exist[key].first + 1;
            exist[key] = { freq , counter} , freq_q[freq].push({ key , counter }) , counter++ , 
            nxt_freq[freq - 1]--;
            nxt_freq[freq]++;
            if (nxt_freq[freq-1] == 0 && mn_freq == freq-1 )
                mn_freq++;
        }
        return (exist[key].second != -1 ? values[key] : -1 );
    }
    
    void put(int key, int value) {
        if (exist.count(key) && exist[key].second != -1){
            int freq = exist[key].first + 1;
            exist[key] = {freq , counter};
            freq_q[freq].push({ key , counter });
            values[key] = value;
            nxt_freq[freq - 1]--;
            nxt_freq[freq]++;
            if (nxt_freq[freq-1] == 0 && mn_freq == freq-1 )
                mn_freq++;
            counter++;
            return;
        }
        // delete first one with less frequency if tie delete LRU
        if ( curr_size >= mx ){
            int freq = mn_freq;
            auto [k , c] = freq_q[freq].front();
            while (exist[k].first != freq || exist[k].second != c) {
                freq_q[freq].pop();
                k = freq_q[freq].front().first , c = freq_q[freq].front().second;
            }
            exist[k] = { -1 , -1};
            freq_q[freq].pop();
            nxt_freq[freq]--;
            curr_size--;
        }
        exist[key] = {1 , counter};
        freq_q[1].push({key , counter});
        values[key] = value;
        curr_size++ , counter++;
        nxt_freq[1]++;
        mn_freq = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */