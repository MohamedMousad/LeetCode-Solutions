class Solution {
    string t;
    vector<string> addresses;
    int cnt = 3;
    void generate_ips(int i , string& s){
        if (i == s.length()){
            if (cnt == 0){
                for (int j = 0; j < t.length() ; j++){
                    int clz = 0 , num = 0;
                    while (j < t.length() && t[j] != '.' && t[j] == '0')
                        clz++ , j++;
                    while (j < t.length() && t[j] != '.' && num <= 255){
                        num*=10;
                        num+=(t[j] - '0');
                        j++;
                    }
                    if (num > 255 || (num > 0 && clz > 0) || (clz > 1 ) )
                        return;
                }
                addresses.push_back(t);
            }
            return;
        }
        t.push_back(s[i]);
        generate_ips(i+1 , s);
        t.pop_back();
        if (!t.empty() && i < s.size() && cnt > 0 && s.back() != '.'){
            t.push_back('.');
            t.push_back(s[i]);
            cnt--;
            generate_ips(i+1 , s);
            cnt++;
            t.pop_back();
            t.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        generate_ips(0 , s);
        return addresses;
    }
};