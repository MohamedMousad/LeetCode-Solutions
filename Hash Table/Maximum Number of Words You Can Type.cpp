class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken [26];
        bool good = true; short ans = 0;
        text.push_back(' ');
        for (int i = 0 ; i < brokenLetters.size() ; i++)
            broken[brokenLetters[i] - 'a'] = true;
        for (int i = 0 ; i < text.size() ; i++){
            if (text[i] == ' '){
                if (good) ans++;
                good = true;
            }
            else if (broken[text[i] - 'a']) good = false;
        }
        return ans;
    }
};