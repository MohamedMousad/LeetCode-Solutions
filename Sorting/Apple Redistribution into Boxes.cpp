class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0 , cnt = 0;
        for (auto& pack : apple)
            sum+=pack;
        sort(capacity.rbegin() , capacity.rend());
        for (auto& cap : capacity){
            sum-=cap , cnt++;
            if (sum <= 0)
                return cnt;
        }
        return cnt;
    }
};