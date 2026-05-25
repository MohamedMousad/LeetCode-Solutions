class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>> not_available;
        priority_queue<long long, vector<long long>, greater<long long>> available;
        vector<int> booked(n);
        for (int i = 0 ; i < n ; i++) {
            available.push(i);
        }
        sort(meetings.begin() , meetings.end());
        for (int i = 0; i < meetings.size() ; i++) {
            long long meetingStart = meetings[i][0] , meetingEnd = meetings[i][1] , 
            period = meetingEnd - meetingStart;
            while (!not_available.empty() && not_available.top().first <= meetingStart) {
                available.push(not_available.top().second);
                not_available.pop();
            }
            if (available.empty() and !(not_available.empty())) {
                not_available.push({max(not_available.top().first, meetingStart) + period , 
                not_available.top().second});
                booked[not_available.top().second]++;
                not_available.pop();
            }
            else if (!available.empty()) {
                not_available.push({meetingStart + period , available.top()});
                booked[available.top()]++;
                available.pop();
            }
        }
        long long ans = 0  , most_booked = 0;
        for (int i = 0 ; i < n ; i++) {
            if (booked[i] > ans) {
                ans = booked[i];
                most_booked = i;
            }
        }
        return most_booked;
    }
};