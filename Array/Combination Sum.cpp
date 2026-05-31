class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    int t =0 , sum = 0;
    void rec(vector<int>& candidates , int start){
        if (sum == t){
            ans.push_back(temp);
            return;
        }
        if (sum > t || start >= candidates.size())
            return;
        for (int i = start ; i < candidates.size() ; i++){
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            rec(candidates , i );
            sum-=candidates[i];
            temp.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        t = target;
        rec (candidates , 0);
        return ans;
    }
};