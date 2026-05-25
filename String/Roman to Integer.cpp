class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char last = '$';
        while (!s.empty()){
            if (s.back() == 'I' && (last == 'V' || last == 'X'))
                ans--;
            else if (s.back() == 'X' && (last == 'L' || last == 'C'))
                ans-=10;
            else if (s.back() == 'C' && (last == 'D' || last == 'M'))
                ans-=100;
            else if (s.back() == 'I')
                ans++;
            else if (s.back() == 'V')
                ans+=5;
            else if (s.back() == 'X')
                ans+=10;
            else if (s.back() == 'L')
                ans+=50;
            else if (s.back() == 'C')
                ans+=100;
            else if (s.back() == 'D')
                ans+=500;
            else if (s.back() == 'M')
                ans+=1000;
            
            last = s.back();
            s.pop_back();
        }
        return ans;
    }
};