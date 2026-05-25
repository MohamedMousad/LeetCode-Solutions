class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0 , odd = 0;
        pair<int,int> alternate = { 0 , 0};
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i]&1){
                odd++;
                if (alternate.second != 1){
                    alternate.first++;
                    alternate.second = 1;
                }
            }
            else{
                even++;
                if (alternate.second != 2){
                    alternate.first++;
                    alternate.second = 2;
                }
            }
        }
        return max(alternate.first , max (even , odd));
    }
};