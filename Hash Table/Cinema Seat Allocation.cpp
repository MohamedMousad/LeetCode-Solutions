class Solution {
    map<int,vector<int>> mp;
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        for (int i = 0 ; i < reservedSeats.size() ; i++)
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        int last = 0;
        long long res = 0;
        for (auto& i : mp){
            res+=((i.first - last - 1)*2);
            last = i.first;
            vector<bool> curr(11 , 0);
            for (auto& seat : i.second)
                curr[seat] = 1;
            for (int start = 2; start < 8 ; start+=2){
                bool good = true;
                for (int j = start ; j < (start + 4 ) ; j++){
                    if (curr[j]) {
                        good = false ;
                        break;
                    }
                    curr[j] = 1;
                }
                if (good) res++;
            }
        }
        res+=((n-last)*2);
        return res;
    }
};