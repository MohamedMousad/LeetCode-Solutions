class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        paths.push_back("/");
        for (int i = 1 ; i < path.size() ;){
            int idx = path.find('/' , i);
            idx = (idx == path.npos ? path.size() : idx);
            int sz = idx - i + 1;
            string dir = path.substr(i , sz);
            i = idx + 1;
            if (!dir.empty() && dir.back() == '/') dir.pop_back();
            if (!dir.empty() && (dir == "."||( dir == ".." && paths.size() <= 1))) continue;
            if (!dir.empty() && dir == ".." && paths.size() > 1)
                paths.pop_back();
            else if (!dir.empty())
                paths.push_back(dir + "/");
        }
        string ans;
        for(auto& s : paths){
            ans+=s;
        }
        if (ans.size() > 1 && ans.back() == '/')
            ans.pop_back();
        return ans;
    }
};