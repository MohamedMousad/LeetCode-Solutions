class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int,int> ans = {0 , 0};
        for (int i = 0 ; i < dimensions.size(); i++){
            int diagonal = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            int area = dimensions[i][0]*dimensions[i][1];
            if (diagonal >= ans.second){
                if (diagonal == ans.second)
                    ans.first = max(ans.first , area);
                else 
                    ans = {area , diagonal};
            }
        }
        return ans.first;
    }
};