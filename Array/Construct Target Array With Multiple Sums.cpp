class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;
        if (target.size() == 1) return target[0] == 1;
        for (int i = 0 ; i < target.size() ; i++){
            sum+=target[i];
            if (target[i] != 1)
                pq.push(target[i]);
        }
        while (!pq.empty()){
            long long diff = sum - pq.top() , top1 = pq.top() , top2 = 1;
            pq.pop();
            if (!pq.empty())
                top2 = pq.top();
            if (top1 - diff <= 0)
                return false;
            long long margin = top1 - top2;
            long long n  = top1 - diff*((margin/diff) == 0 ? 1 : (margin/diff));
            sum -=( diff*((margin/diff) == 0 ? 1 : (margin/diff)));
            if (n != 1)
                pq.push(n);
        }
        return true;
    }
};