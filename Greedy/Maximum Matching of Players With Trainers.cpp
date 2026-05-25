class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());
        int i = trainers.size() - 1 , j = players.size() -1 , cnt = 0;
        while (i >= 0 && j >= 0){
            if (trainers[i] >= players[j]){
                cnt++;
                i--;
            }
            j--;
        }
        return cnt;
    }
};