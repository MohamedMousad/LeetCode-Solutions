class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int,int>> st;
        for (int i = 0 ; i < logs.size() ; i++){
            int id = stoi(logs[i].substr( 0 , logs[i].find(':')));
            if ( logs[i].find('s') != logs[i].npos){
                int start = stoi(logs[i].substr(logs[i].find("t:") + 2));
                st.push({id , start});
            }
            else {
                int end = stoi(logs[i].substr(logs[i].find('d') + 2));
                int sum = 0 ;
                while (st.top().first == -1){
                    sum+=st.top().second;
                    st.pop();
                }
                int curr = ( end - st.top().second + 1) - sum;
                sum = ( end - st.top().second + 1);
                st.pop();
                st.push({-1 , sum});
                ans[id]+=curr;
            }
        }
        return ans;
    }
};