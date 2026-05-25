class Solution {
public:
    int calculate(string s) {
        stack<long long> results;
        stack<char> op;
        string num = "";
        long long ans = 0;
        s.push_back(')');
        for (int i = 0 ; i < s.size() ; i++){
            if( s[i] == '-' || s[i] == '+' || s[i] == ')' || s[i] == '('){
                if (!num.empty())
                    results.push(stoll(num));
                num = "" , ans = 0;
                if (s[i] == '(' &&( op.empty() || ( op.top() != '+' && op.top() != '-')))
                    op.push('+');
                if (s[i] == ')'){
                    long long last = 0 , ans = 0;
                    while (!op.empty() && op.top() != '('){
                        if (!results.empty())
                            last = results.top() , results.pop();
                        if (op.top() == '+')
                            ans += last;
                        else
                            ans -= last;
                        op.pop();
                    }
                    results.push(ans);
                    if(!op.empty()) op.pop();
                }
                else
                    op.push(s[i]);
            }
            else if (s[i] <= '9' && s[i] >= '0') {
                if (op.empty() || op.top() == '(' || op.top() == ')')
                    op.push('+');
                num.push_back(s[i]);
            }
        }
        return results.top();
    }
};