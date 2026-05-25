class Solution {
public:
    int bitwiseComplement(int n) {
    bitset<32> b(n);
    if (n == 0 )
        return 1;
    int k = __lg(n); 
    for (int i = 0; i <= k; i++)
        b.flip(i);
    return b.to_ullong(); 
    }
};