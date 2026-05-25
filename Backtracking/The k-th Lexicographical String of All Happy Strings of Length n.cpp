class Solution {
    const string elems = "abc";
    string t  ,ans ;
    void generate_string(int n , int& k , char last){
        if (k == 1 )
            ans = t;
        if (t.size() == n){
            k--;
            return;
        }
        if (k > 0 ){
            for (int i = 0 ; i < elems.size() ; i++){
                if (last == elems[i]) continue;
                t.push_back(elems[i]);
                    generate_string(n , k , elems[i]);
                t.pop_back();
            }
        }
    } 
public:
    string getHappyString(int n, int k) {
        generate_string(n , k , '$');
        return ans;
    }
};