class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int> mp;
        for (int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        int ans= 0;
        bool odd = 0;
        for (auto& x : mp){
            ans+=((x.second/2)*2);
            odd |= (x.second %2 != 0);            
        }
        return ans + odd ;
    }
};