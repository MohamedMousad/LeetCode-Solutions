class Trie {
    Trie* arr [26] = {};
    bool isLeaf = false;
public:
    Trie() {
    }
    void insert(string word) {
        auto *curr = this;
        for (int i= 0 ; i < word.size() ; i++){
            if (!curr->arr[word[i] - 'a'])
                curr->arr[word[i] - 'a'] = new Trie();
            curr = curr->arr[word[i] - 'a'];
        }
        curr->isLeaf = true;
    }
    bool search(string word) {
        auto *curr = this;
        for (int i= 0 ; i < word.size() ; i++){
            if (!curr->arr[word[i] - 'a'])
                return false;
            curr = curr->arr[word[i] - 'a'];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        auto  *curr = this;
        for (int i= 0 ; i < prefix.size() ; i++){
            if (!curr->arr[prefix[i] - 'a'])
                return false;
            curr = curr->arr[prefix[i] - 'a'];
        }
        return true;
    }
};