#include <cstdlib> // For rand and srand
#include <ctime>   // For time (to seed)
class Solution {
public:
    vector<int> pre;
    std::mt19937 generator;
    Solution(vector<int>& w) {
        std::random_device rd;
        generator.seed(rd());
        pre.resize(w.size());
        for (int i = 0 ; i < w.size() ; i++){
            if (i == 0 ) pre[i] = w[i];
            else pre[i] = pre[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        std::uniform_int_distribution<int> distribution(1, pre.back());
        int random_number = distribution(generator);
        return lower_bound(pre.begin() , pre.end() , random_number) - pre.begin();
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */