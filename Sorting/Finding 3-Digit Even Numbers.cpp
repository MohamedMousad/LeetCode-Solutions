class Solution {
public:
    bool check_num(int num , vector<int>freq){
        while(num){
            freq[(num%10)]--;
            if (freq[num%10] < 0){
                return false;
            }
            num/=10;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>freq(10);
        vector<int> ans;
        for (int i = 0 ; i < digits.size();i++){
            freq[digits[i]]++;
        }
        for (int i = 100 ; i < 1000 ;i++){
            if (i%2 == 0 && check_num(i , freq))
                ans.push_back(i);
        }
        return ans;
    }
};