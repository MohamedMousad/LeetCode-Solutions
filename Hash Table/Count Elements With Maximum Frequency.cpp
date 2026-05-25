class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        char freq [101] = {} , mx = 0;
        for (auto& num : nums)
            freq[num]++ , mx = (freq[num] > mx ? freq[num] : mx);
        for (short i = 1 ; i <= 100 ; i++)
            if (freq[i] == mx) freq[0]+=mx;
        return (freq[0]);
    }
};