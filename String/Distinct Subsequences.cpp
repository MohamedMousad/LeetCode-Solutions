class Solution {
    vector<vector<int>> dp;
    string ss  , tt;
    int rec(int i , int j){
        if (j >= tt.size())
            return 1;
        if (i >= ss.size())
            return 0;
        int& ret =  dp[i][j];
        if (~ret) return ret;
        int sum = 0;
        if (ss[i] == tt[j])
            sum+=rec(i+1 , j+1);
        sum+=rec(i+1 , j);
        return ret = sum;
    }
public:
    int numDistinct(string s, string t) {
        dp.resize(s.size() + 5);
        for (auto& i : dp)
            i.assign(t.size() + 5 , -1);
        ss = s , tt = t;
        return rec(0 , 0);        
    }
};