class Router {
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                h ^= std::hash<int>()(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
    unordered_map<int , deque<int>> destination_map = {};
    unordered_set<vector<int> , VectorHash> visited;
    queue<vector<int>> current = {};
    int max_size;
public:
    Router(int memoryLimit): visited() {
        max_size = memoryLimit;
    }
    bool CanAdd(int source, int destination, int timestamp) {
        return true;
    }
    bool addPacket(int source, int destination, int timestamp) {
        if (visited.find({source , destination , timestamp}) != visited.end()) return false;
        visited.insert({source , destination , timestamp});
        current.push({source , destination , timestamp});
        destination_map[destination].push_back(timestamp);
        if (current.size() > max_size) forwardPacket();
        return true;
    }
    vector<int> forwardPacket() {
        vector<int> curr ;
        if (!current.empty()) {
            curr = current.front();
            current.pop();
            destination_map[curr[1]].pop_front();
            visited.erase({curr[0] , curr[1] , curr[2]});
        }
        return curr;
    }

    int getCount(int destination, int startTime, int endTime) {
        int start = lower_bound(destination_map[destination].begin() , destination_map[destination].end() , startTime) - destination_map[destination].begin();
        int end = upper_bound(destination_map[destination].begin() , destination_map[destination].end() , endTime) - destination_map[destination].begin();
        return end - start;
    }
};