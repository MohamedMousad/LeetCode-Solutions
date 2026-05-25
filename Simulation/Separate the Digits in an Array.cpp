class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> temp;
        for (int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            while (num){
                temp.push(num%10);
                num/=10;
            }
            while (!temp.empty()){
                ans.push_back(temp.top());
                temp.pop();
            }
        }
        return ans;
    }
};