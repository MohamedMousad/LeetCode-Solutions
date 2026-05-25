class Solution {
public:
    string addBinary(string a, string b) {
        string s;
            bitset<10001> ans(0);
    int carry = 0;
    int i = a.length() - 1 , j = b.length() - 1 , k = 0;
    for (  ; i >= 0 && j >= 0 ; i-- , j-- , k++)
    {
        int ones = 0 ;
        if (a[i] == '1')
            ones++;
        if (b[j] == '1')
            ones++;
        if (ones + carry == 1)
        {
            if (carry) carry = 0;
            ans[k] = 1;
        }
        else if (ones + carry == 2)
        {
            carry = 1;
            ans[k] = 0;
        }
        else if (ones + carry == 3)
        {
            ans[k] = 1;
        }
    }
    while ( i >= 0)
    {
        if (carry + (a[i] - '0') == 2)
        {
            carry = 1;
            ans[k] = 0;
        }
        else if (carry + (a[i] - '0') == 0)
        {
            carry = 0;
            ans[k] = 0;
        }
        else
        {
            carry = 0;
            ans[k] = 1;
        } 
        i--;k++;
    }
    while ( j >= 0)
    {
        if (carry + (b[j] - '0') == 2)
        {
            carry = 1;
            ans[k] = 0;
        }
        else if (carry + (b[j] - '0') == 0)
        {
            carry = 0;
            ans[k] = 0;
        }
        else 
        {
            carry = 0;
            ans[k] = 1;
        } 
        j--;k++;
    }
    if (carry > 0)
    {
        ans[k] = 1;
        k++;
    }
    while (k >= 1)
    {
        --k;
        s.push_back(ans[k] + '0');
    }
        return s;
    }
};