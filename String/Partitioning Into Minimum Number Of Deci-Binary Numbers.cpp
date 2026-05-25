class Solution {
public:
    int minPartitions(string n) {
        short ans = 0;
        for (int i = 0 ; i < n.length() ; i++){
            ans = max (ans ,(short)( n[i] - '0'));
        }
        return ans;
    }
};