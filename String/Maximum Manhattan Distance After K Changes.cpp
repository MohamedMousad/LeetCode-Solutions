class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> freq(26);
        int mx = -1000000009 , ans = 0;
        char lessy = 'a' , lessx = 'a';
        for (int i = 0 ; i < s.length() ;i++){
            freq[s[i] - 'A']++;
            int sum = abs(freq['N'- 'A'] - freq['S' - 'A'] ) + abs(freq['E' - 'A'] - freq['W' - 'A']) + 2*k;
            mx = max(mx , min(sum , i+1));
        }
        return mx;
    }
};