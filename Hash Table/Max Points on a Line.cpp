class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx = 1;
        for (int i = 0 ; i < points.size() ; i++){
            pair<int,int> point1 = {points[i][0] , points[i][1] };
            unordered_map<double,int> mp;
            for (int j = 0 ; j < points.size() ; j++){
                if (i == j ) continue;
                pair<int,int> point2 = {points[j][0] , points[j][1] };
                double slope = (points[i][1] - points[j][1])/(double)(points[i][0] - points[j][0]);
                mp[slope]++;
                mx = max(mx , mp[slope]+1);
            }
        }
        return mx;
    }
};