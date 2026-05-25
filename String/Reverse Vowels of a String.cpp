class Solution {
public:
    string reverseVowels(string s) {
        string t ;
        for (auto& ch : s ){
            char c = tolower(ch);
            if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                t.push_back(ch);
        }
        reverse(t.begin() , t.end());
        int i = 0;
        for (auto& ch : s ){
            char c = tolower(ch);
            if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ch = t[i++];
        }
        return s;
    }
};