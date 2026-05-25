class Solution {
    string form_word(int row ){
        if (row == 0)
            return "0";
        string s = form_word(row - 1);
        string t = s;
        for (int i = 0 ; i < s.size() ; i++)
            s[i] = (s[i] == '1' ? '0' : '1');
        reverse(s.begin() , s.end());
        return t + "1" + s;
    }
public:
    char findKthBit(int n, int k) {
        string ans = form_word( n);
        return ans[k-1];
    }
};