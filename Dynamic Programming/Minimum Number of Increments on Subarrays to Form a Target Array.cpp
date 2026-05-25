class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size()  , ans = 0;
        deque<int> a; a.push_back(target[0]);
        for (int i = 1 ; i < n ; i++){
            while (!a.empty() && target[i] < a.back()){
                if (target[i] < a.back() && a.size() == 1){
                    ans+=abs(a.back() - target[i]) , a.pop_front();
                    break;
                }
                if (target[i] < a.back() && a.size() > 1)
                    ans+=abs(a.back() - max(a[a.size() - 2 ] , target[i])) , a.pop_back();
                else
                    break;
            }
            if (a.empty() || target[i] != a.back())
                a.push_back(target[i]);
        }
        if (!a.empty()) ans+=a.back();
        return ans;
    }
};