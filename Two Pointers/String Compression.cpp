class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), l = 0;
        for (int i = 0 ; i < n ;){
            char t = chars[i];
            int cnt = 0 ; 
            while (i < n && t == chars[i]) i++ , cnt++;
            chars[l++] = t;
            if (cnt > 1){
                string s = to_string(cnt);
                for (int j = 0 ; j < s.size(); j++) chars[l++] = s[j];
            }
        }
        return l;
    }
};