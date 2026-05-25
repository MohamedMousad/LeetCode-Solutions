class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0 , small = 0;
        for (auto& ch : word){
            if (ch >= 'A' && ch <= 'Z')
                cap++;
            else 
                small++;
        }
        if (small && cap)
            return word[0] >= 'A' && word[0] <= 'Z' && cap == 1;
        else 
            return true;
    }
};