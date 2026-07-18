class Solution {
    bool get_cost(string& first , string& second){
        int cost= 0;
        for (int i = 0 ; i < first.size() ; i++){
            cost+=(first[i] != second[i]);
        }
        return cost == 1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bool vis[12] = {};
        queue<pair<int,int>> q;
        q.push({bank.size() , 0});
        vis[bank.size()] = true;
        bank.push_back(startGene);
        while (!q.empty()){
            auto [idx , cost] = q.front(); q.pop();
            for (int i = 0  ; i < bank.size() ; i++){
                if (!vis[i] && get_cost(bank[idx] , bank[i]))
                    q.push({i, cost+1}) , vis[i] = true;
            }
            if (bank[idx] == endGene)
                return cost;
        }
        return -1;
    }
};