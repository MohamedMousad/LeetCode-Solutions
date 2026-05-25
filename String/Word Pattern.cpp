class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char , string> mp;
        unordered_map<string , char> mp2;
        int cnt = 0;
        for (int i = 0 , j = 0 ; i < s.size() ; i++ , j++ , cnt++){
            string t;
            while (i < s.size() && s[i] != ' ') t.push_back(s[i++]);
            if ( mp.find(pattern[j]) == mp.end() ) mp[pattern[j]] = t;
            else if (mp[pattern[j]] != t) return false;
            if ( mp2.find(t) == mp2.end() ) mp2[t] = pattern[j];
            else if (mp2[t] != pattern[j]) return false;
        }
        if (pattern.size() != cnt)
            return false;
        return true;
    }
};