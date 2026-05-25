class Solution {
public:
    int maxFreqSum(string s) {
        short mx_con = 0 , mx_vowel = 0 ;
        short freq[26] = {};
        for (short i = 0 ; i < s.length() ; i++){
            freq[s[i] - 'a']++;
        }
        for (short i = 0 ; i < 26 ; i++){
            if (i == ('a' - 'a') || i == ('e' - 'a') || i == ('i' - 'a') || i == ('o' - 'a') || i == ('u' - 'a'))
                mx_vowel = max(mx_vowel , freq[i]);
            else 
                mx_con = max(mx_con , freq[i]);
        }
        return mx_con + mx_vowel;
    }
};