class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        int freq [255] = {};
        for (int i = 0 ; i < s.length(); i++){
            if (vowels.find(s[i]) != vowels.npos){
                freq[(int)s[i]]++;
            }
        }
        int index = 'A';
        for (int i = 0 ; i < s.length(); i++){
            if (vowels.find(s[i]) != vowels.npos){
                while (freq[index] == 0) index++;
                s[i] = (char)(index);
                freq[index]--;
            }
        }
        return s;
    }
};