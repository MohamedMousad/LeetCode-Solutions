class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int if_hold = -prices[0];
        int cash = 0;
        
        for(int i=1;i<prices.size();i++){
            if_hold = max(if_hold, cash - prices[i]);
            cash =  max(cash, if_hold + prices[i] - fee);

        }

        return cash;

        
    }
};