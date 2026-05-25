class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size() , cnt = 0;
        vector<pair<char , int>> st(n);
        for (int i = 0 ; i < n; i++)
            st[i] = {s[i] , i};
        sort(st.begin() , st.end());
        // NEW 
        for (char i = 'a' ; i <= 'z'; i++){
            for (char j = 'a' ; j <= 'z'; j++){
                auto it = lower_bound(st.begin() , st.end() , pair<char, int>{i , 0});
                if (it == st.end() || it->first != i) break;
                auto it2 = lower_bound(st.begin() , st.end() , pair<char, int>{j , it->second + 1});
                if (it2 == st.end() || it2->first != j) continue;
                auto it3 = lower_bound(st.begin() , st.end() , pair<char, int>{i , it2->second + 1});
                if (it3 == st.end()|| it3->first != i) continue;
                cnt++;
            }
        }
        return cnt;
    }
};