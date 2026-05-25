class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0 , en = 0 , n = s.size() , mx = 0; 
        for (int i = 0 ; i < n ;i++ ){
            int l = i , r = i;
            while (l >= 0 && r < n && s[l] == s[r])
                l-- ,r++;
            if (r - l - 1 > mx)
                st = l + 1, en = r - 1 , mx = r - l - 1;
            
            l = i , r = i+1;
            while (l >= 0 && r < n && s[l] == s[r])
                l-- ,r++;
            
            if (r - l - 1 > mx)
                st = l + 1, en = r - 1 , mx = r - l - 1;
        }
        return s.substr(st , en - st + 1);
    }
};