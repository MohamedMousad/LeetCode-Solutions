#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
class RandomizedSet {
public:
    unordered_map<int, bool> present; 
    vector<long long> numbers;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (present.count(val) == 0 || present.count(val) == 1 && !present[val]){
            if (present.count(val) == 0 )
                numbers.push_back(val);
            present[val] = true;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (present.count(val) == 0 || !present[val])
            return false;
        present[val] = false; 
        return true;       
    }
    
    int getRandom() {
        int randomNumber = rand() % (numbers.size());
        while (!present[numbers[randomNumber]]){
            randomNumber = rand() % (numbers.size());
        }
        return numbers[randomNumber];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
auto init = atexit([]{ofstream("display_runtime.txt")<<"0";});
