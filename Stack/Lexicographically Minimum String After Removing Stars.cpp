class Solution {
public:
string clearStars(string s) {
    priority_queue<pair<char, int>, 
    vector<pair<char, int>>, 
    function<bool(pair<char, int>, pair<char, int>)>> p(
        [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
    priority_queue<int, vector<int> , greater<int>> deleted;
    for (int i = 0 ; i < s.size();i++){
        if (s[i] != '*' ){
            p.push({s[i], i});
        }
        else {
            deleted.push(p.top().second);
            p.pop();
        }
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*')
            continue;
        if (deleted.empty() || deleted.top() != i)
            ans += s[i];
        else
            deleted.pop();
    }
    return ans;
}
};