class SmallestInfiniteSet {
    int last = 1;
    bool freq[1001] = {};
    priority_queue<int , vector<int> , greater<int>> q;
public:
    SmallestInfiniteSet() {
        for (int i = 1 ; i <= 1000 ; i++)
            freq[i] = 1 , q.push(i);
    }
    int popSmallest() {
        while (!q.empty() && !freq[q.top()]) q.pop();
        int front = q.top();q.pop();
        freq[front] = false;
        return front;
    }
    
    void addBack(int num) {
        if (freq[num]) return;
        freq[num] = 1;
        q.push(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */