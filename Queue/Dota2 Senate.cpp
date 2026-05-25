class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int n = senate.size();
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()) {
            int r_q = r.front();
            int d_q = d.front();
            r.pop();
            d.pop();
            if(r_q < d_q) {
                r.push(r_q+n);
            }
            else d.push(d_q+n);
        }
        if(d.empty()) {
            return "Radiant";
        }
        else return "Dire";
    }
};