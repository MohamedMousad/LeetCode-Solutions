class Solution {
public:
    int binaryGap(int n) {
    bitset<32> b(n);
    int index_1 =0 , ans = 0 , index_2 = 0;
    if (b.count() <= 1)
    {
        return 0;
    }
    index_1 = __lg(b.to_ullong());
    b.reset(index_1);
    while (b.count() >= 1)
    {
        index_2 = __lg(b.to_ullong());
        b.reset(index_2);
        if (index_1 - index_2 > ans)
        {
            ans = index_1 - index_2;
        }
        index_1 = index_2;
    }
    return ans;
        
    }
};