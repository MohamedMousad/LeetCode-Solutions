class Solution {
    int par[100005] = {};
    int size[100005] = {};
    int find(int j ){
        if (par[j] == j) return j;
        return par[j] = find(par[j]);
    }
    void merge(int i , int j){
        int first = find(i) , sec = find(j);
        if (first == sec)   
            return;
        if (size[first] < size[sec])
            swap(first , sec);
        par[sec] = par[first];
        size[first]+=size[sec];
    }
    bool check(int u , int v ,  vector<vector<int>>& adj , int n){
        int ugroup = find(u) , vgroup = find(v);
        if (ugroup == vgroup)
            return true;
        bool good = true;
        unordered_set<int> denied;
        unordered_set<int> groupu;
        for (int j = 0 ; j < n ; j++){
            int union_group = find(j);
            if (union_group == ugroup){
                groupu.insert(j);
                for (auto& num : adj[j])
                    denied.insert(num);
            }
        }
        for (int j = 0 ; j < n ; j++){
            int union_group = find(j);
            if (union_group == vgroup){
                if(denied.count(j) != 0)
                    return false;
                for (auto& num : adj[j]){
                    if (groupu.count(num) != 0)
                        return false;
                }
            }
        }
        return good;
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans(requests.size(), false);
        vector<vector<int>> adj(n , vector<int>());
        for (int i = 0 ; i < restrictions.size() ; i++){
            int u = restrictions[i][0] ,  v = restrictions[i][1]; 
            adj[u].push_back(v) , adj[v].push_back(u);
        }
        for (int i = 0; i < n ; i++)
            par[i] = i , size[i] = 1;
        for (int i = 0; i < requests.size() ; i++){
            int u = requests[i][0], v = requests[i][1];
            bool good = check(u , v , adj , n);
            if (good) merge(u , v);
            ans[i] = good;
        }
        return ans;
    }
};