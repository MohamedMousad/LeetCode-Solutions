class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>> table;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        pair<int,string> find = {timestamp , ""};
        auto it = upper_bound( table[key].begin() , table[key].end() , find ,  
        [&](const pair<int, string>& a ,const pair<int, string>& b ){
            return a.first < b.first;
        });
        if (it == table[key].begin() )
            return "";
        else  
            return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */