class Solution {
public:
    int maxDistance(string moves) {
        int u = 0 , l = 0 , both = 0 ;
        for (int i = 0 ; i < moves.size(); i++){
            if (moves[i] == 'U')
                u++;
            else if (moves[i] == 'D')
                u--;
            else if (moves[i] == 'L')
                l++;
            else if (moves[i] == 'R')
                l--;
            else 
                both++;
        }
        int ans = abs(u) + abs(l) + both;
        return ans;
    }
};