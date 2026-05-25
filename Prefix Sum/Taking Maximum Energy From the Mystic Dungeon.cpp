class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = -INT_MAX;
        for (int i = energy.size() - 1 ; i>= 0 ; i--){
            if (i+k < energy.size())
                energy[i]+= energy[i+k];
            ans = (ans > energy[i] ? ans : energy[i]);
        }
        return ans;
    }
};