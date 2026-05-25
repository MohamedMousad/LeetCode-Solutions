class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int ans = -1 ,mod = 1e9 + 7;
        unordered_map<int , bool > diff;
        vFences.push_back(n) , hFences.push_back(m);
        sort(hFences.begin() , hFences.end());
        sort(vFences.begin() , vFences.end());
        for (int i = 0 ; i < vFences.size() ; i++){
            for (int j = i ; j < vFences.size() ; j++){
                diff[vFences[j] -( i == j ? 1 : vFences[i])] = true;
            }
        }
        for (int i = 0 ; i < hFences.size() ; i++){
            for (int j = i ; j < hFences.size() ; j++){
                if (diff.count(hFences[j] - ( i == j ? 1 : hFences[i])) != 0)
                    ans = max(ans ,hFences[j] - ( i == j ? 1 : hFences[i]) );
            }
        }
        long long t = (long long)ans*ans % mod;
        return ans != -1 ? t : -1;
    }
};