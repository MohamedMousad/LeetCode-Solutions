class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int ans = 0;
        for (int i = 0 ; i < tickets.size() ; i++)
            q.push(i);
        while (tickets[k] > 0){
            int front = q.front();
            tickets[front]--;
            q.pop();
            if (tickets[front]) q.push(front);
            ans++;
        }
        return ans;
    }
};