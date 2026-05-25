class RecentCounter {
public:
    int recent = 0;
    queue<int> op;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        recent++;
        op.push(t);
        while (!op.empty() && op.front() < t - 3000 )
            recent-- , op.pop();
        return recent;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */