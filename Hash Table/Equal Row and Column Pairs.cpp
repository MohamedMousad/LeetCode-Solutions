class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        auto hashCode = [](const vector<int> &v) {
            hash<int> hasher;
            size_t res = 0;
            for (int i : v) {
                res ^= hasher(i) + 0x9e3779b9 + (res << 6) + (res >> 2);
            }
            return res;
        };


        unordered_map<size_t, int> mp;
        for (auto &g: grid) ++mp[hashCode(g)];
        
        int res = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> k;
            for (int i = 0; i < n; ++i) {
                k.push_back(grid[i][j]);
            }
            size_t h = hashCode(k);
            if(mp.count(h)) res += mp[h];
        }
        return res;
    }
};