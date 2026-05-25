class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin() , citations.rend());
        int ans = 0 , n = citations.size() ;
        for (int i = 0 ; i < n ; i++){
            if (i+1 <= citations[i]) ans = i+1;
        }
        return ans;
    }
};