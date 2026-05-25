class Solution {
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        string smax = "", smin = "";
        int mx = 0, mn = 0 , index = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '9' && index == -1) index = i;
            if (s[i] != '9' && s[i] == s[index])
                smax.push_back('9');
            else
                smax.push_back(s[i]);
            if (s[i] == s[0])
                smin.push_back('0');
            else
                smin.push_back(s[i]);
        }
        mx = stoi(smax);
        mn = stoi(smin);
        return abs(mx - mn);
    }
};