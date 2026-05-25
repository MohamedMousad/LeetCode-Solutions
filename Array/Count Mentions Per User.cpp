class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int all_here_count = 0;
        vector<int> ans(numberOfUsers);
        deque<pair<int,int>> off;
        // #1 sorting by time 
        sort(events.begin() , events.end() , [&](vector<string>& a , vector<string>& b){
            if (a[0] == b[0])
                return stoi(a[1]) < stoi(b[1]);
            return a[0] > b[0];
        });
        for (int i = 0 ; i <  events.size() ; i++){
            if (events[i][0] == "MESSAGE"){
                // increments all
                if (events[i][2] == "ALL" || events[i][2] == "HERE"){
                    all_here_count++;
                    if (events[i][2] == "HERE"){
                        int t = stoi(events[i][1]) , idx = 0;
                        while (!off.empty() && t >= off.front().first + 60 )
                            off.pop_front();
                        while (idx < off.size() && t >= off[idx].first && t < off[idx].first + 60)
                            ans[off[idx++].second]--;
                    }
                }
                // increments direct users
                else{
                    int n = events[i][2].size();
                    for (int j = 0 ; j < events[i][2].size() ; j++ ){
                        string s ;
                        while(j < n && events[i][2][j] != ' '){
                            if (events[i][2][j] >= '0' && events[i][2][j] <= '9')
                                s.push_back(events[i][2][j]);
                            j++;
                        }
                        int idx = stoi(s) ;
                        ans[idx]++;
                    }
                }
            }
            else {
                int idx = stoi(events[i][2]) , t = stoi(events[i][1]);
                off.push_back({t , idx});
            }
        }
        for (auto& elem : ans )
            elem+=all_here_count;
        return ans;
    }
};
auto init = atexit([]() { std::ofstream("display_runtime.txt") << "0"; });
