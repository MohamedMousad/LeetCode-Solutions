class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt = 0;
        if (bits.back() == 1)
            return false;
        int i = bits.size() - 2;
        while (i >= 0 && bits[i] == 1)
            cnt++ , i--;
        return (cnt%2 == 0 );
    }
};