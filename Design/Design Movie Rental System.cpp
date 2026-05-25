class MovieRentingSystem {
public:
set<tuple<int, int, int>> all;
unordered_map<int, set<pair<int, int>>> movies;
unordered_map<int, unordered_map<int, int>> info;
vector<int> v;
vector<vector<int>> vv;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& e : entries) {
            info[e[1]][e[0]] = e[2];
            movies[e[1]].insert({e[2], e[0]});
        }
    }
    
    vector<int>& search(int movie) {
        v.resize(min(5, (int) size(movies[movie])));
        for (int in = -1; const auto& [price, shop] : movies[movie]) if (++in == 5) return v; else v[in] = shop;
        return v;
    }
    
    void rent(int shop, int movie) {
        int price = info[movie][shop];
        all.insert({price, shop, movie});
        movies[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = info[movie][shop];
        all.erase({price, shop, movie});
        movies[movie].insert({price, shop});
    }
    
    vector<vector<int>>& report() {
        vv.resize(min(5, (int) size(all)), vector<int>(2));
        for (int in = -1; const auto& [price, shop, movie] : all) if (++in == 5) return vv; else vv[in][0] = shop, vv[in][1] = movie;
        return vv;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */