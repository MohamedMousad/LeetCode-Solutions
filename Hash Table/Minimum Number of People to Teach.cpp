class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<short> language_freq(n+1);
        vector<bool> vis(languages.size()+1);
        short sum = 0;
        for (int i = 0 ; i < languages.size() ; i++){
            sort(languages[i].begin() , languages[i].end());
        }
        for (short i = 0 ; i < friendships.size() ; i++){
            short first = friendships[i][0]-1 , second = friendships[i][1]-1;
            bool flag = 0;
            for (int j = 0 , k = 0 ; j <  languages[first].size() && k < languages[second].size();){
                if (languages[first][j] == languages[second][k]){
                    flag = 1;
                    break;
                }
                else if (languages[first][j] < languages[second][k] )
                    j++;
                else 
                    k++;
            }
            if (!flag){
                if (!vis[first]){
                    for (int j = 0 ; j < languages[first].size() ; j++)
                        language_freq[languages[first][j]]++;
                    sum++;
                    vis[first] = 1;
                }
                if (!vis[second]){
                    for (int j = 0 ; j < languages[second].size() ; j++)
                        language_freq[languages[second][j]]++;
                    sum++;
                    vis[second] = 1;
                }
            }
        }
        short mx = *max_element(language_freq.begin() , language_freq.end());
        return (int)(sum - mx);
    }
};