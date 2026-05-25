class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool delete_first_row = 0 , delete_first_col = 0;
        for (int i = 0 ; i < matrix.size() ; i++){
            for (int  j = 0 ; j < matrix[i].size() ; j++){
                if (matrix[i][j] == 0){
                    if (j == 0) delete_first_col = 1;
                    if (i == 0) delete_first_row = 1;
                    if(i !=0 && j != 0){
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1 ; i < matrix.size(); i++){
            if (matrix[i][0] == 0){
                for (int j = 1; j < matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0 ; i < matrix[0].size() ; i++){
            if (matrix[0][i] == 0){
                for (int j = 1 ; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        if (delete_first_row){
            // clean first row 
            for (int j = 0 ; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
            }
        }
        if (delete_first_col){
            // clean first column
            for (int j = 0 ; j < matrix.size() ; j++){
                matrix[j][0] = 0;
            }
        }
    }
};