class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (int i = 0 ; i < words.size() ;){
            ans.push_back(words[i]);
            string s1 = words[i]; 
            sort(s1.begin() , s1.end());
            while (i < words.size() ){
                string s2 = words[i];
                sort(s2.begin() , s2.end());
                if (s1 != s2) break;
                i++;
            }
        }
        return ans;
    }
};