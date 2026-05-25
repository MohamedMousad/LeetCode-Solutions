class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        int word1count[26]={0}, word2count[26]={0};
        for(char ch: word1){
            word1count[ch-'a']++;
        }
        for(char ch: word2){
            word2count[ch-'a']++;

            if(word1count[ch-'a']==0)
                return false;
        }
        sort(word1count, word1count+26);
        sort(word2count, word2count+26);

        for(int i=0;i<26;i++){
            if(word1count[i]!=word2count[i])
                return false;
        }

        return true;
    }
};