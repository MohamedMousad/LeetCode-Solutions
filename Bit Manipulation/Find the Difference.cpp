class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0 , sum2 = 0 , ans = 0;
        for (auto i : s)
        {
            ans = ans^i;
        }
        for (auto i : t)
        {
            ans = ans^i;
        }
        return char(ans);
    }
};