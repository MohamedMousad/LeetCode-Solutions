class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        long long base1 = 31, mod1 = 1e9 + 7;
        long long base2 = 37, mod2 = 1e9 + 9;
        
        long long forward1 = 0, reverse1 = 0, power1 = 1;
        long long forward2 = 0, reverse2 = 0, power2 = 1;
        
        int longest_palindrome_prefix = 0;
        
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1; 
            
            forward1 = (forward1 * base1 + val) % mod1;
            reverse1 = (reverse1 + val * power1) % mod1;
            power1 = (power1 * base1) % mod1;
            
            forward2 = (forward2 * base2 + val) % mod2;
            reverse2 = (reverse2 + val * power2) % mod2;
            power2 = (power2 * base2) % mod2;
            
            if (forward1 == reverse1 && forward2 == reverse2) {
                longest_palindrome_prefix = i + 1;
            }
        }
        string suffix = s.substr(longest_palindrome_prefix);
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};