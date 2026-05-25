class Solution {
public:
    int findComplement(int num) {
    bitset<32> b(num);
    int k = __lg(num); 
    for (int i = 0; i <= k; i++)
        b.flip(i);
    return b.to_ullong(); 
    }
};