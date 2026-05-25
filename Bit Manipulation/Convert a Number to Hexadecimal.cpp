#include <bits/stdc++.h>
class Solution {
public:
    string toHex(int num) {
        string ans;
            long long n;
            if (num == 0) return "0";
            if (num < 0) {
                n = unsigned(num);
            }
            else n = num;
            while (n != 0)
            {
                int digit = n %16;
                if (digit >= 10)
                {
                    ans.push_back(digit - 10 + 'a');
                }
                else 
                {
                    ans.push_back(digit + '0');
                }
                n/= 16;
            }
            reverse(ans.begin() , ans.end());
        return ans;
    }
};