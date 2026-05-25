class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        short drunk = 0 , empty = 0;
        while (numBottles){
            drunk+= numBottles;
            empty+=numBottles;
            numBottles = 0;
            while (empty >= numExchange){
                numBottles++;
                empty-=numExchange;
                numExchange++;
            }
        }
        return drunk;
    }
};