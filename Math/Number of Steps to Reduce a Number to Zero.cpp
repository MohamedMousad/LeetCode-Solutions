#include <bits/stdc++.h>
#include <bitset>
class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0)
            return num;
        return __lg(num) +  __popcount(num);
    }
};