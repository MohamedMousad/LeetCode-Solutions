class Solution {
    vector<int> deg , odd;
    bool can_connect(int u , int v, vector<vector<int>>& edges){
        if (u > v) swap(u , v);
        vector<int> tmp= {u , v};
        auto it = lower_bound(edges.begin() , edges.end() , tmp);
        if (it == edges.end()) return true;
        auto ans = *it;
        if ( ans[0] != u || ans[1] != v)
            return true;
        return false;
    }
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        deg.resize(n+1 , 0);
        for (int i = 0; i < edges.size() ; i++){
            deg[edges[i][1]]++;
            deg[edges[i][0]]++;
            if (edges[i][1] < edges[i][0])
                swap(edges[i][1] , edges[i][0]);
        }
        sort(edges.begin() , edges.end());
        for (int i = 0; i <= n ; i++){
            if (deg[i]&1) odd.push_back(i);
        }
        if (odd.empty()) return true;
        // (odd <-> odd) or( odd <-> even <-> odd)
        if (odd.size() == 2 ){
            if (can_connect(odd[0] , odd[1] , edges))
                return true;
            for (int i = 1 ; i <= n ; i++)
                if (i != odd[0] && i != odd[1] && can_connect(odd[0] , i , edges) && can_connect(odd[1] , i , edges))
                    return true;
        }
        // (odd <-> odd) and ( odd <-> odd)
        if (odd.size() == 4 && ((can_connect(odd[0] , odd[1] , edges) && can_connect(odd[2] , odd[3] , edges)) ||
                                (can_connect(odd[0] , odd[2] , edges) && can_connect(odd[1] , odd[3] , edges)) ||
                                (can_connect(odd[0] , odd[3] , edges) && can_connect(odd[1] , odd[2] , edges))) ){
                return true;
        }
        return false;
    }
};