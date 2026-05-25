class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> convert;
        unordered_map<char,bool> characters;
        if (s.size() != t.size()) return false;
        for (int i = 0 ; i < s.size(); i++){
            if (convert.count(s[i]) == 0) {
                if (characters[t[i]]) return false;
                convert[s[i]] = t[i];
                characters[t[i]] = 1;
            }
            if (convert[s[i]] != t[i] ) return false ;
        }
        return true;
    }
};