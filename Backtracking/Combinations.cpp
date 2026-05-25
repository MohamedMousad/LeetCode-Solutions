class Solution {
    vector<int> a ;
    vector<vector<int>> ans;
    void rec(int i  , int n , int k ){
        if (i > n){
            if (a.size() == k)
                ans.push_back(a);
            return;
        }
        a.push_back(i);
        rec(i+1 , n , k);
        a.pop_back();
        rec(i+1 , n , k);
        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        rec(1,n ,k);
        return ans;        
    }
};