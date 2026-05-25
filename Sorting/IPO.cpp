class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> pq;
        vector<pair<int,int>> cp(n);
        for (int i = 0 ; i < n ; i++)
            cp[i] = {capital[i] , profits[i]};
        sort(cp.begin() , cp.end());
        int cnt = 0 , l = 0;
        while (cnt < k){
            while (l < n && w >= cp[l].first)
                pq.push(cp[l].second) , l++; 
            if (!pq.empty())      
                w+=pq.top() , pq.pop() , cnt++;
            else
                break;
        }
        return w;
    }
};