class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {} , upper [26] = {};
        for (int i = 0 ; i < word.size() ; i++){
            if (word[i] <= 'z' && word[i] >= 'a' && lower[word[i] - 'a'] != -1){
                lower[word[i] - 'a'] = 1;
                if (upper[word[i] - 'a'] == 1)
                    lower[word[i] - 'a'] = -1;
            }
            else if (word[i] <= 'Z' && word[i] >= 'A')
                upper[word[i] - 'A'] = 1;
        }
        int sum = 0;
        for (int i = 0; i < 26 ;i++){
            if (lower[i] == 1 && upper[i] == 1)
                sum++;
        }
        return sum;
    }
};