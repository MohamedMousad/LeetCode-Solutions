class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 0 , last = 0 , last_sz = 0 , curr = 0 , last_idx;
        if (ratings.size() <= 1)
            return 1;
        for (int i = 0 ; i < ratings.size() - 1;){
            bool good = false;
            int sz = 1 , last_idx = i;
            while(i < ratings.size() - 1 && ratings[i] < ratings[i+1])
                sz++ , i++ , good = true , curr = 1 ;
            if (!good){
                while(i < ratings.size() - 1 && ratings[i] == ratings[i+1])
                    sz++ , i++ , good = true , curr = 0;
            }
            if (!good){
                while(i < ratings.size() - 1 && ratings[i] > ratings[i+1])
                    sz++ , i++ , curr = -1;
            }
            if (last == 1 && curr == -1){
                if (last_sz >= sz){
                    sz--;
                    count+=(sz*(sz+1)/2);
                }
                else{
                    count-=last_sz;
                    count+=(sz*(sz+1)/2);
                }
            }
            else {
                if (curr == 0){
                    count+=(sz-2);
                    if (i == ratings.size() - 1)
                        count++;
                    if (last_idx == 0)
                        count++;
                }
                else {
                    count+=(sz*(sz+1)/2);
                }
                if (last == -1 && curr == 1)
                    count--;
            }
            last_sz = sz , last = curr;
        }
        return count;
    }
};