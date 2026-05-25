class MedianFinder {
    priority_queue<int> mn_numbers;
    priority_queue<int, vector<int> , greater<int>> mx_numbers;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mn_numbers.push(num);
        bool is_even = ( mn_numbers.size() + mx_numbers.size() )%2 == 0;
        if ( mn_numbers.size() > mx_numbers.size() + !is_even)
            mx_numbers.push(mn_numbers.top()) , mn_numbers.pop();
        if (!mn_numbers.empty() && !mx_numbers.empty() && mn_numbers.top() > mx_numbers.top()){
            auto first = mn_numbers.top() , sec = mx_numbers.top();
            mn_numbers.pop() , mx_numbers.pop();
            mx_numbers.push(first) , mn_numbers.push(sec);
        }
    }
    
    double findMedian() {
        bool is_even = ( mn_numbers.size() + mx_numbers.size() )%2 == 0;
        return (is_even ?(double)( mn_numbers.top() + mx_numbers.top())/2.0 : mn_numbers.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */