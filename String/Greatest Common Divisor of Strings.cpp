class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If the strings are not made of the same repeating pattern, return empty string
        if(str1 + str2 != str2 + str1) return "";  // fixed extra space
        int len = gcd(str1.length(), str2.length());
        return str1.substr(0, len);
    }

    int gcd(int a, int b) {
        if(b == 0) return a;  // fixed typo "retun"
        return gcd(b, a % b); // fixed wrong return syntax
    }
};