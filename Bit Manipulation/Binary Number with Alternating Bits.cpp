class Solution {
public:
    bool hasAlternatingBits(int n) {
        auto last = -1;
        for (int i = 0 ;i <= __lg(n) ; i++){
            bool bit  = (((1LL<<i) & n) > 0 ? 1 : 0);
            if (bit != last)
                last = bit;
            else
                return false;
        }
        return true;
    }
};