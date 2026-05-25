class Solution {
public:
    string maskPII(string s) {
        bool number = 0;
        string filtered ;
       for (int i = 0 ; i < s.size() ; i++){
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') 
            ||( s[i] <= '9' && s[i] >= '0' ) || s[i] == '.' || s[i] == '@'){
                if ( s[i] <= '9' && s[i] >= '0')
                    number = 1;
                filtered.push_back(s[i]);
            }
       }
       if (number){
            string temp = "***-***-";
            string ans;
            int i = filtered.size() ;
            while (i > 10){
                if (i == filtered.size())
                    ans.push_back('+');
                ans.push_back('*');
                i--;
            }
            if (!ans.empty())
                ans.push_back('-');
            ans = ans + temp;
            for ( i = filtered.size() - 4 ; i < filtered.size() ; i++ ){
                ans.push_back(filtered[i]);
            }
            return ans;
       }
       else {
            string temp = "*****";
            string ans;
            ans.push_back(tolower(filtered[0]));
            ans = ans + temp;
            for (int i = filtered.find('@') - 1 ; i < filtered.size() ; i++ ){
                if ( filtered[i] >= 'A' && filtered[i] <= 'Z')
                    ans.push_back(tolower(filtered[i]));
                else
                    ans.push_back(filtered[i]);
            }
            return ans;     
       }
    }
};