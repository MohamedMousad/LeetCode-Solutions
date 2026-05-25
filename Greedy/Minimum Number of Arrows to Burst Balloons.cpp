class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end() , [&](vector<int>& a , vector<int>& b) {
            return a[1] < b[1];
        });
        int last = -1 , cnt = 0; 
        for (int i = 0 ; i < points.size() ; i++){
            if (last == -1 || last < points[i][0])
                last = points[i][1] , cnt++;
        }
        return cnt;
    }
};