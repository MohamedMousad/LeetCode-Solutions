class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0 ; i < nums.size() ; i++){
            int start = nums[i];
            while (i+1 < nums.size() && nums[i] + 1 ==  nums[i+1])
                i++;
            int end = nums[i];
            string s;
            s+=to_string(start);
            if (start != end){
                s += "->";
                s+=to_string(end);
            }
            ans.push_back(s);
        }
        return ans;
    }
};