class RangeFreqQuery {
    vector<int> freq[10005];
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0 ; i < arr.size() ; i++){
            freq[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto r = upper_bound(freq[value].begin() , freq[value].end() , right);
        auto l = lower_bound(freq[value].begin() , freq[value].end() , left);
        return (int)(r - l);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */