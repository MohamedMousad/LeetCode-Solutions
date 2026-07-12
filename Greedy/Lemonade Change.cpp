class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int twenties = 0 , tens = 0 , five = 0;
        for (int i = 0; i < bills.size() ; i++){
            int change = bills[i] - 5;
            while (change >= 20 && twenties){
                change-=20;
                twenties--;
            }
            while (change >= 10 && tens){
                change-=10;
                tens--;
            }
            while (change >= 5 && five){
                change-=5;
                five--;
            }
            if (change)
                return false;

            if (bills[i] == 20)
                twenties++;
            else if (bills[i] == 10)
                tens++;
            else
                five++;
        }
        return true;
    }
};