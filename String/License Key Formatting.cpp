class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        auto f = [](char& c ){return( c >= 'a' &&c  <= 'z') || ( c >= 'A' &&c  <= 'Z');};
        string ans;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0  ; i-- ){
            if (f(s[i]) || (s[i] >= '0' && s[i] <= '9') ){
                if (cnt%k == 0 && cnt != 0)
                    ans.push_back('-');
                ans.push_back((f(s[i]) ? toupper(s[i]) : s[i]));
                cnt++;
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};