class SummaryRanges {
    unordered_map<int,bool> available;
    map<pair<int,int> , bool> intervals;
    vector<int> par , sz ,  mn , mx;
    int find(int child)
    {
        if (par[child] == child) return child;
        return par[child] = find(par[child]);
    }

    bool join(int u, int v)
    {
        u = find(u) , v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        mn[u] = min(mn[u] , mn[v]);
        mx[u] = max(mx[u] , mx[v]);
        par[v] = u , sz[u] += sz[v];
        return true;
    }
public:
    SummaryRanges() {
        par.resize(10005) , sz.resize(10005) , mn.resize(10005) , mx.resize(10005);
        for (int i = 0; i < 10000 + 5; i++)
            par[i] = mx[i] = mn[i] =  i, sz[i] = 1;
    }

    void addNum(int value) {
        if (available[value])
            return;
        available[value] = true;
        if (available.count(value+1) > 0){
            int root = find(value+1);
            pair<int,int> interval = {mn[root] , mx[root]};
            intervals[interval] = false;
            join(value , value+1);
        }
        if (available.count(value - 1) > 0){
            int root = find(value-1);
            pair<int,int> interval = {mn[root] , mx[root]};
            intervals[interval] = false;
            join(value , value-1);
        }
        int root = find(value);
        pair<int,int> interval = {mn[root] , mx[root]};
        intervals[interval] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& interval : intervals){
            if(interval.second)
                ans.push_back({interval.first.first , interval.first.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */