class MyCalendarTwo {
    vector<pair<int,int>> ones , twos ;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (auto& [ s , e] : twos){
            if (max(startTime , s) < min(e , endTime))
                return false;
        }
        for (auto& [ s , e] : ones){
            if (max(startTime , s) < min(e , endTime)){
                twos.emplace_back(max(s, startTime) , min(e , endTime));
            }
        }
        ones.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */