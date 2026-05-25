class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,bool> mp;
        vector<string> ans;
        sort(folder.begin() , folder.end());
        for (int i = 0 ; i < folder.size(); i++){
            bool flag = 1;
            string t = "";
            for (auto & ch : folder[i]){
                if (!t.empty() && ch == '/' && mp.find(t) != mp.end()){
                    flag = 0;
                    break;
                }
                t.push_back(ch);
            }
            if (flag){
                mp[t] = 1;
                ans.push_back(t);
            }
        }
        return ans;
    }
};