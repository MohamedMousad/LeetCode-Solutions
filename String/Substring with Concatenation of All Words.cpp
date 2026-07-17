class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_sz = words[0].size();
        unordered_map<string, int> wordsmap ; 
        vector<int> res;
        for (int i = 0 ; i < words.size() ; i++)
            wordsmap[words[i]]++;
        for (int i = 0 ; i < word_sz ; i++){
            int cnt = 0 , deleted = 0;
            string tmp;
            unordered_map<string, int> mp;
            vector<string> list;
            for (int j = i , c = 0 ; j < s.size() ; j++ , c++){
                if (c % word_sz == 0 && !tmp.empty()){
                    list.push_back(tmp) , tmp = "";
                    if (cnt < words.size())
                        mp[list.back()]++ , cnt++;
                }
                tmp.push_back(s[j]);
            }
            if (!tmp.empty()) {
                list.push_back(tmp);
                if (cnt < words.size())
                    mp[list.back()]++ , cnt++;
            }
            while (deleted + words.size() <= list.size()){
                if (wordsmap == mp)
                    res.push_back(i + deleted*word_sz);
                mp[list[deleted]]--;
                if ( mp[list[deleted]] == 0 )
                    mp.erase(list[deleted]);
                if (deleted + words.size() < list.size())
                    mp[list[deleted + words.size()]]++;
                deleted++;
            }
        }
        return res;
    }
};