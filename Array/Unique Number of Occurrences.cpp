class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2010] = {}; bool freq2[1010] = {};
        for (auto& num : arr)
            freq[num + 1005]++;
        for (int i = 1 ; i < 2010 ; i++){
            if (freq2[freq[i]])
                return false;
            if (freq[i] != 0)
                freq2[freq[i]] = 1;
        }
        return true;
    }
};