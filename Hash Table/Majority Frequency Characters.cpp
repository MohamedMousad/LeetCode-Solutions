class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int freq[26] = {};
        map<int,string> mp;
        string ans;
        for (int i = 0 ; i < s.size() ; i++) freq[s[i] - 'a']++;
        for (int i = 0 ; i < 26 ; i++){
            if (freq[i])
            mp[freq[i]].push_back((char)(i+'a'));
        }
        for (auto& i : mp){
            if (ans.size() <= i.second.size()) ans = i.second;
        }
        return ans;
    }
};