class Solution {
    vector<int> ans;
    void rec(int start , int end , int increment, bool sw){
        if ( end - start > increment ){
            sw = (((end - start)/ increment) + 1)%2 == 1 ? true : false ;
            rec( start , sw == true ? end  : end - increment , increment<<1  , sw);
            rec(start + increment ,  sw == true ? end - increment : end , increment<<1 , sw);
        }
        else {
            for (int i = start ; i <= end ; i+=increment)
                ans.push_back(i);
        }
    }
public:
    vector<int> beautifulArray(int n) {
        rec(1 , n , 1 , n%2 == 1);
        return ans;
    }
};