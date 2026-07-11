class Solution {
    class trie{
        public:
        map<char , trie*> t;
        bool isleaf = false;
        string ans ;
        string temp;
        trie(){};
        trie(vector<string> words){
            for (auto& word : words){
                add(word);
            }
        };
        void add(string& s){
            auto curr = this;
            for (auto& ch : s){
                if (curr->t.count(ch) == 0)
                    curr->t[ch] = new trie();
                curr = curr->t[ch];
            }
            curr->isleaf = true;
        }
        void findLongest(trie* curr = nullptr){
            if(!curr)
                curr = this;
            for (auto& nxt : curr->t){
                if (nxt.second->isleaf){
                    temp.push_back(nxt.first);
                    findLongest(nxt.second);
                    if (ans.size() < temp.size())
                        ans = temp;
                    temp.pop_back();
                }
            }
        }
    };
public:
    string longestWord(vector<string>& words) {
        trie* t= new trie(words);
        t->findLongest();
        return t->ans;
    }
};