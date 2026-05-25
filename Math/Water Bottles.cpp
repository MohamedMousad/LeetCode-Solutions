class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = 0 , empty = 0;
        while (numBottles){
            drunk+= numBottles;
            empty+=numBottles;
            numBottles = empty / numExchange ;
            empty%= numExchange;
        }
        return drunk;
    }
};