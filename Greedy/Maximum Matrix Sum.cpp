class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0 , mn = INT_MAX , cnt = 0 ; 
        for (int i = 0 ; i < matrix.size(); i++){
            for (int j = 0 ; j < matrix.size(); j++){
                if ( matrix[i][j] < 0 )
                    matrix[i][j] = -matrix[i][j] , cnt++;
                mn = min(mn ,(long long)(matrix[i][j]));
                ans+=matrix[i][j];
            }
        }
        return ( cnt%2 != 0 ?  ans - (mn<<1) : ans  );
    }
};