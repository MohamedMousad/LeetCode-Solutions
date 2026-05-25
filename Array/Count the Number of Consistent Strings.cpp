class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int not_allowed = 0;
        bitset<26> freq(0);
        for (int i = 0 ; i < allowed.length();i++)
        {
            freq[allowed[i]- 'a'] = 1;
        }
        for (int i = 0 ; i < words.size();i++){
            for (int j = 0 ; j < words[i].length();j++){
                if(freq[words[i][j] - 'a'] == 0){
                    not_allowed++;
                    break;
                }
            }
        }
        return words.size() - not_allowed;
    }
};