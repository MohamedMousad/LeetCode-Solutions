class WordDictionary {
    map<char , WordDictionary*> dict;
    bool isleaf = false;
public:
    WordDictionary() {
        
    }

    void addWord(string word) {
        auto *curr =this;
        for (int i = 0 ; i < word.size() ; i++){
            if (curr->dict.count(word[i]) == 0)
                curr->dict[word[i]] = new WordDictionary();
            curr = curr->dict[word[i]];
        }
        curr->isleaf = true;
    }
    


    bool search(const string& word , WordDictionary* curr = nullptr) {
        if (!curr)
            curr = this;
        for (int i = 0 ; i < word.size(); i++){
            if (word[i] == '.'){
                string temp = word.substr(i+1);
                bool ch = false;
                for (auto new_curr : curr->dict){
                    ch |=search(temp , new_curr.second);
                    if (ch)
                        return ch;
                }
                return ch;
            }
            else if (curr->dict.count(word[i]) == 0)
                return false;
            curr = curr->dict[word[i]];
        }
        return curr && curr->isleaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */