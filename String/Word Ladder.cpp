class Solution {
    bool get_cost(string& first , string& second){
        int cost= 0;
        for (int i = 0 ; i < first.size() ; i++){
            cost+=(first[i] != second[i]);
        }
        return cost == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<int> st;
        for (int i = 0 ; i < wordList.size() ; i++)
            st.insert(i);
        bool vis[5005] = {};
        queue<pair<int,int>> q;
        q.push({wordList.size() , 0});
        vis[wordList.size()] = true;
        wordList.push_back(beginWord);
        while (!q.empty()){
            auto [idx , cost] = q.front(); q.pop();
            queue<int> toDelete;
            for (auto& i : st){
                if (!vis[i] && get_cost(wordList[idx] , wordList[i]))
                    q.push({i, cost+1}) , vis[i] = true , toDelete.push(i);
            }
            while (!toDelete.empty()){
                if(st.count(toDelete.front()));
                    st.erase(toDelete.front());
                toDelete.pop();
            }
            if (wordList[idx] == endWord)
                return cost + 1;
        }
        return 0;
    }
};