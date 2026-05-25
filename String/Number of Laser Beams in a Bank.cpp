class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0 , ans = 0; 
        for (int i = 0 ; i < bank.size() ; i++){
            int cnt = 0;
            for (int j = 0 ; j < bank[i].size() ; j++) cnt+=(bank[i][j] > '0');
            if (cnt) ans+= (last*cnt) , last = cnt;
        }
        return ans;
    }
};