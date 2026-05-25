class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int max = 0 , cnt = 0 , segment1 = 0;
        map<int,int> doms ;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            doms[nums[i]]++;
            if (doms[nums[i]] > cnt ) 
            {
                cnt = doms[nums[i]];
                max = nums[i];
            }
        }
        if (cnt <= (nums.size() / 2))
        {
            return -1;
        }
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] == max )
            {
                segment1++;
            }
            int x = (i+1)/2;
            int y = (nums.size() - i - 1)/ 2;
            if (segment1 > x && (cnt - segment1) > y)
            {
                return i;
            }
        }
        return -1;
    }
};