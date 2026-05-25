class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0 , r = 0 ;long long sum = n;
        for (int i = 1; i < n ; i++){
            if (i < r)
                z[i] = min(r - i , z[i - l]);
            
            while (z[i] + i < n && s[z[i] + i] == s[z[i]]){
                z[i]++;
            }
            
            if (i + z[i] > r)
                l = i , r = i + z[i];
        }
        for (auto& score : z )
            sum+=score;
        return sum;
    }
};