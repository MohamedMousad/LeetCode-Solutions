class Solution {
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
    void appendWords(vector<string>& words , string& word , Trie* trie){
        auto* curr = trie;
        if (words.size() >= 3) return;
        if (curr->isLeaf) words.push_back(word);
        for (int i = 0 ; i < 26 ; i++){
            if (curr->arr[i]){
                word.push_back((i + 'a'));
                appendWords(words , word , curr->arr[i]);
                word.pop_back();
            }
        }
    }
    vector<string> suggest(string word){
        auto  *curr = this;
        for (int i= 0 ; i < word.size() ; i++){
            if (!curr->arr[word[i] - 'a'])
                return vector<string>();
            curr = curr->arr[word[i] - 'a'];
        }
        vector<string> words;
        appendWords(words , word , curr);
        return words;
    }
};
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto trie = new Trie();
        for (int i = 0 ; i < products.size() ; i++)
            trie->insert(products[i]);
        string s;
        vector<vector<string>> ans;
        for (int i = 0 ; i < searchWord.size() ; i++){
            s.push_back(searchWord[i]);
            ans.push_back(trie->suggest(s));
        }
        return ans;
    }
};