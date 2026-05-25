class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0  , r= matrix.size() - 1 , ans = 0;
        while (l <= r ){
            int mid = ((l + r)>>1);
            (matrix[mid][0] <= target ? ans = mid , l = mid + 1 : r = mid - 1);
        }
        auto it = lower_bound(matrix[ans].begin() , matrix[ans].end() , target);
        return (it != matrix[ans].end() && *it == target);
    }
};