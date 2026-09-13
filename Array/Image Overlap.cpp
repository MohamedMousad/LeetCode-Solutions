class Solution {
    vector<pair<int, int>> mul = {{1 , 1} , {1 , -1} , {-1 , 1}, {-1 , -1}};
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int mx = 0;
        for (int i = 0 ; i < img1.size() ; i++){
            for (int j = 0 ; j < img1.size() ; j++){
                for (int o = 0 ; o < 4 ; o++){
                    int row_shift = i*mul[o].first , col_shift = j*mul[o].second , cnt = 0;
                    for (int k = 0 ; k < img2.size() ; k++){
                        for (int l = 0 ; l < img2.size() ; l++){
                            if ((k + row_shift) < img2.size() && (l + col_shift) < img2.size() &&  (k + row_shift) >= 0 && (l + col_shift) >= 0 && 
                            ( img1[k][l] == img2[k+row_shift][l+col_shift] )&& img1[k][l]) 
                                cnt++;
                        }
                    }
                    mx = max(cnt , mx);
                }
            }
        }
        return mx;
    }
};