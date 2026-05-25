class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> prefix(n , vector<int>(n , 0));
        for (int i = 0 ; i < queries.size() ; i++){
            prefix[queries[i][0]][queries[i][1]]++;
            if (queries[i][3] + 1 < n )
                prefix[queries[i][0]][queries[i][3] + 1]--;
            if (queries[i][2] + 1 < n )
                 prefix[queries[i][2]+1][queries[i][1]]--;
            if (queries[i][2] + 1 < n && queries[i][3] + 1 < n )
                 prefix[queries[i][2]+1][queries[i][3]+1]++;

        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
        return prefix ;
    }
};