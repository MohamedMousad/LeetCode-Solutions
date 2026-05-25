class LRUCache {
    int mx = 0 , curr_size = 0 , counter = 0;
    unordered_map<int,int> exist , values;
    queue<pair<int,int>> q;
public:
    LRUCache(int capacity) {
        mx = capacity;
    }
    
    int get(int key) {
        if (exist.count(key) == 0)
            return -1;
        if ( exist[key] != -1)
            exist[key] = counter , q.push({ key , counter }) , counter++;
        return (exist[key] != -1 ? values[key] : -1 );
    }
    
    void put(int key, int value) {
        if (exist.count(key) && exist[key] != -1){
            exist[key] = counter;
            q.push({key , counter});
            values[key] = value;
            counter++;
            return;
        }
        if ( curr_size >= mx ){
            while (exist[q.front().first] != q.front().second) q.pop();
            exist[q.front().first] = -1;
            q.pop();
            curr_size--;
        }
        exist[key] = counter;
        q.push({key , counter});
        values[key] = value;
        curr_size++ , counter++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */