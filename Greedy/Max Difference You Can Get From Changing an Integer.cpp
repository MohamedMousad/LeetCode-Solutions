class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string smax = "", smin = "" ; char c = 'k';
        int mx = 0, mn = 0 , index = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '9' && index == -1) index = i;
            if (s[i] != '9' && s[i] == s[index]) smax.push_back('9');
            else smax.push_back(s[i]);
        }
        for (int i = 0; i < s.length(); i++){
            if ( (s[i] > '1'  && c == 'k') || ( i > 0 && s[i] != s[0] && c == 'k' && s[i] != '0')) {
                c = s[i];
                index = i;
            }
            if (s[i] == c){
                if (index == 0)
                    smin.push_back('1');
                else 
                    smin.push_back('0');
            }
            else {
                smin.push_back(s[i]);
            }
        }
        mx = stoi(smax);
        mn = stoi(smin);
        if (mn == 0){
            smin.clear();
            for (int i = 0; i < s.length(); i++){
                smin.push_back('1');
            }
        }
        mn = stoi(smin);
        return abs(mx - mn);
    }
};