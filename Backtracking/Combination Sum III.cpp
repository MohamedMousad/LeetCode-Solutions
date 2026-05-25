class Solution {
    bool vis[10];
    vector<int> a ;
    vector<vector<int>> ans;
    void rec(int i , int n ,int k ){
        if (i == 10){
            if (a.size() == k){
                int sum = 0;
                for (auto& elem : a )
                    sum+=elem;
                if (sum == n)
                    ans.push_back(a);
            }
            return;
        }
        a.push_back(i);
        rec(i+1 , n , k );
        a.pop_back();
        rec(i+1 , n , k );
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        rec(1 , n , k);
        return ans;
    }
};