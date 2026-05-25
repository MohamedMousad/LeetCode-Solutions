class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // Lambda function for comparison
        auto cmp = [](int x, int y) {
            int countX = __builtin_popcount(x), countY = __builtin_popcount(y);
            return countX == countY ? x < y : countX < countY;
        };
        
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};