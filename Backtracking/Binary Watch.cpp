class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> final ;
        int limit = 1 << 10 ;
        for (int msk = 0 ; msk < limit;msk++)
        {
            string h , m;
            bitset<10> bs (msk);
            if (bs.count() == turnedOn)
            {
                bitset<4>hours;
                bitset<6> minutes;
                for (int i = 0; i < 6; ++i) {
                    minutes[i] = bs[i];
                }
                for (int i = 0; i < 4; ++i) {
                    hours[i] = bs[i+ 6];
                }
                if(hours.to_ulong() <= 11 && minutes.to_ulong() <= 59)
                {
                    h = to_string(hours.to_ulong());
                    m = to_string(minutes.to_ulong());
                    if (m.length() == 1) m = '0' + m;
                    final.push_back(h + ':' + m);
                }
            }
        }
        return final;
    }
};