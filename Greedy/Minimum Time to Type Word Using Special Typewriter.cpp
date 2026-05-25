class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char pointer = 'a';
        for (int i = 0 ; i < word.size() ; i++){
            ans += (word[i] >= pointer ? min((int)(word[i] - pointer) ,26 - (int)(word[i] - pointer)) : 
                                        min((int)(pointer - word[i]) , 26 - (int)(pointer - word[i])));
            pointer = word[i];
        }
        return ans + word.size();
    }
};