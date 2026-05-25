class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        deque<short> s;
        while (x){
            s.push_back(x%10);
            x/=10;
        }
        while (s.size() >= 2 && s.back() == s.front() ){
            s.pop_back();
            s.pop_front();
        }
        return s.size() <= 1 ;
    }
};