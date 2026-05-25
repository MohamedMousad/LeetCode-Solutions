class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circle = 0, square = 0 ; 
        queue<int> q;
        for (auto& i : students){
            q.push(i);
            if (i == 0) circle++;
            else square++;
        }
        int i = 0 ;
        while (i < sandwiches.size() &&
         ((circle > 0 && sandwiches[i] == 0) || (square > 0 && sandwiches[i] == 1)) ){
            if (!q.empty() && q.front() == sandwiches[i]){
                if (q.front() == 0) circle--;
                else square--;
                i++ , q.pop();
            }
            else {
                int x = q.front();
                q.pop();
                q.push(x);
            }
         }
        return q.size();
    }
};