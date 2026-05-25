class Solution {
public:
    bool judgeCircle(string moves) {
        short ver = 0, hor = 0;
        for (auto& move : moves)
            hor+= ( (move == 'R') - ( move == 'L')) , ver+=((move == 'U') - ( move == 'D'));
        return (hor | ver) ==  0;
    }
};