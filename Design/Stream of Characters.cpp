class StreamChecker {
public:
    class trie{
        public:
        map<char , trie* > nxt;
        bool leaf = false;
        trie(){};
        void insert(const string& word){
            trie* curr = this;
            for (int i = 0 ; i < word.size(); i++){
                if (curr->nxt.count(word[i]) == 0)
                    curr->nxt[word[i]] = new trie();
                curr = curr->nxt[word[i]];
            }
            curr->leaf = true;
        }
        bool isSuffix(const string& word){
            trie* curr = this;
            for (int i= word.size() - 1; i>= 0 ; i--){
                if (curr->nxt.count(word[i])){
                    if (curr->nxt.count(word[i]) && curr->nxt[word[i]]->leaf)
                        return true;
                    curr = curr->nxt[word[i]];
                }
                else 
                    return false;
            }
            return false;
        }
    };
    trie* tr = nullptr;
    string current ;
    StreamChecker(vector<string>& words) {
        tr = new trie();
        for (auto& word : words){
            reverse(word.begin() , word.end());
            tr->insert(word);
        }
    }
    bool query(char letter) {
        current.push_back(letter);
        return tr->isSuffix(current);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */