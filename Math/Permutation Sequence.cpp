class Solution {
public:
    string getPermutation(int n, int k) {
        string ans; 
        bool vis [10] = {};
        int sum = 1 , curr = 1;
        for (int j = 1; j <= n ; j++) sum*=j;
        for (int i = n ; i >= 1 ; i--){
            sum /= i;
            int skip = 0;
            while (curr + sum <= k )
                curr +=sum , skip++;
            for (int k = 1 ; k <= n ; k++){
                if (skip == 0 && !vis[k]){
                    vis[k] = true , ans.push_back((char)(k + '0'));
                    break;
                }
                if (!vis[k] && skip)
                    skip--;
            }
        }
        return ans;
    }
};