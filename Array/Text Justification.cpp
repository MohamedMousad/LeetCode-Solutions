class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i = 0 ; i < words.size() ; i++){
            int first = i , sum = words[i].size();
            string s;
            while (i + 1 < words.size() && sum+1+words[i+1].size() <= maxWidth)
                sum+=( words[i+1].size() + 1) , words[i].push_back(' ')  , i++;
            if (i != words.size() - 1){
                while(sum < maxWidth )
                    for (int k = first ; k <= i ; k++)
                        if(sum < maxWidth && (k == first || k < i )) words[k].push_back(' ') , sum++;
            }
            else {
                while (sum < maxWidth)
                    words[i].push_back(' ') , sum++;
            }
            for (int k = first ; k <= i ; k++) s+=words[k];
            res.push_back(s);
        }
        return res;
    }
};