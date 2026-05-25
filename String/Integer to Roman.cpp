class Solution {
public:
    string intToRoman(int num) {
        vector<int> digits;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        string ans;
        while(!digits.empty()){
            int digit= digits.back() , n = digits.size();
            digits.pop_back();
            if (n > 3 ){
                while (digit--)
                    ans+="M";
            }
            else if (n > 2 ){
                if (digit == 9)
                    ans+="CM" , digit-=9;
                else if (digit == 4)
                    ans+="CD" , digit-=4;
                else if (digit >= 5)
                    ans+="D" , digit-=5;
                while (digit--)
                    ans+="C";
            }
            else if (n > 1 ){
                if (digit == 9)
                    ans+="XC" , digit-=9;
                else if (digit == 4)
                    ans+="XL" , digit-=4;
                else if (digit >= 5)
                    ans+="L" , digit-=5;
                while (digit--)
                    ans+="X";
            }
            else{
                if (digit == 9)
                    ans+="IX" , digit-=9;
                else if (digit == 4)
                    ans+="IV" , digit-=4;
                else if (digit >= 5)
                    ans+="V" , digit-=5;
                while (digit--)
                    ans+="I";
            }
        }
        return ans;
    }
};