class RangeModule {
    vector<vector<int>> intervals , intervals2;
public:
    RangeModule() {
    }
    void addRange(int left, int right) {
        intervals2.clear();
        bool done = false;
        for (int i = 0 ; i < intervals.size() ; i++){
            if (left > intervals[i][1]){
                intervals2.push_back({intervals[i][0] , intervals[i][1]});
                continue;
            }
            else if (right < intervals[i][0]){
                if (!done) intervals2.push_back({left , right});
                intervals2.push_back({intervals[i][0] , intervals[i][1]});
                done = true;
                continue;
            }
            else {
                int end = right , start = min(left , intervals[i][0]);
                while (i < intervals.size() && intervals[i][0] <= end)
                    end = max(intervals[i++][1] , end);
                i--;
                intervals2.push_back({start , end});
                done = true;
            }
        }
        if (intervals2.empty() || left > intervals2.back()[1] )
            intervals2.push_back({left , right});
        intervals.swap(intervals2);
    }
    void removeRange(int left, int right) {
        intervals2.clear();
        int start = left  , end = right;
        for (int i = 0 ; i < intervals.size() ; i++){
            if (left <= intervals[i][0] && right >= intervals[i][1])
                continue;
            if (intervals[i][0] < start && start < intervals[i][1] ){
                intervals2.push_back({intervals[i][0] , start});
                if (intervals[i][1] >= end)
                    intervals2.push_back({end , intervals[i][1]});
            }
            else if (intervals[i][0] < end && end < intervals[i][1] )
                intervals2.push_back({end , intervals[i][1]});
            else
                intervals2.push_back({intervals[i][0] , intervals[i][1]});
        }
        intervals.swap(intervals2);
    }
    bool queryRange(int left, int right) {
        int l = 0 , r = intervals.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if (intervals[mid][0] <= left && intervals[mid][1] >= right)
                return true;
            else if (intervals[mid][0] > right)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};

