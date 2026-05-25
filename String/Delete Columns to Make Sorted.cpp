class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt= 0;
        for (int j = 0 ; j < strs[0].size() ; j++){
            int test = 0;
            for (int i = 0 ; i < strs.size() ; i++){
                if ((strs[i][j] - 'a') >= __lg(test))
                    test |=(1<<(strs[i][j] - 'a'));
                else {   
                    cnt++;
                    break; 
                }
            }
        }
        return cnt;
    }
};