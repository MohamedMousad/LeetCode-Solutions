class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        deque<int> back;
        for (int i = 1 ; i <= sqrtl(n) ; i++){
            if (n%i == 0) {
                if (i * i != n) 
                    back.push_front(n/i);
                count++;
            }
            if (count == k) return i;
        }
        k -=count;
        return k > back.size() ? -1 : back[k-1];
    }
};