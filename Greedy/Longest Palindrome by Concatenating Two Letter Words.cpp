class Solution {
public:
    int longestPalindrome(vector<string> &words)
    {
        map<string, int> mp;
        int ans = 0, flag = 0;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = i; j < 26; j++)
            {
                string t = "", k = "";
                t.push_back(i + 'a');
                t.push_back(j + 'a');
                k.push_back(j + 'a');
                k.push_back(i + 'a');
                if (mp.find(t) == mp.end() || mp.find(k) == mp.end())
                    continue;
                if (t != k)
                {
                    ans += (min(mp[t], mp[k]) * 4);
                }
                else
                {
                    int score = mp[t];
                    ans += ((score / 2) * 4);
                    score -= ((score / 2)*2);
                    if (score)
                        flag = 1;
                }
            }
        }
        if (flag)
            ans += 2;
        return ans;
    }
};