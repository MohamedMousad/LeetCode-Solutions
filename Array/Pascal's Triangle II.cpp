class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a ; a.push_back(1);
        for (int i = 1 ; i <= rowIndex ; i++){
            vector<int> b;
            b.push_back(1);
            for (int j = 0; j < a.size() - 1 ; j++){
                b.push_back(a[j] + a[j+1]);
            }
            b.push_back(1);
            a.swap(b);
        }
        return a;
    }
};