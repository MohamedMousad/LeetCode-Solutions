class Solution {
    bool isSelfDividingNumber(int n ){
        int temp = n ;
        while (temp){
            int k = temp%10;
            if (k == 0 || (n%k) != 0)
                return false;
            temp/=10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left ; i <= right ; i++){
            if (isSelfDividingNumber(i))
                ans.push_back(i);
        }
        return ans;
    }
};