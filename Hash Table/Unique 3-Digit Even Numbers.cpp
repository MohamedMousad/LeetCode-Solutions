class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt = 0;
        bool arr[1000] = {};
        for (int i = 0 ; i < digits.size() ; i++){
            if (digits[i] == 0)
                continue;
            for (int j = 0 ; j < digits.size(); j++){
                if (i == j)
                    continue;
                for (int k  = 0 ; k < digits.size() ; k++){
                    if (j == k || i == k)
                        continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if (num%2 == 0 && !arr[num])
                        cnt++ , arr[num] = true;
                }
            }
        }
        return cnt;
    }
};