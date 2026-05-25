class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.length() < k ){
            int limit = s.length();
            for (int i = 0 ; i < limit ; i++){
                s.push_back((char)((((s[i] - 'a')+1)%26) + 'a'));
            }
        }
        return s[k-1];
    }
};