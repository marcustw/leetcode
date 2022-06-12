class Trie {
private:
    Trie* next[26]={};
    bool isWord=false;
    
public:    
    Trie() {}
    
    void insert(string word) {
        Trie* cur=this;
        for (int i=0; i<word.length(); i++) {
            int idx=word[i]-'a';
            if (!cur->next[idx]) cur->next[idx] = new Trie();
            cur=cur->next[idx];
        }
        cur->isWord=true;
    }
    
    bool search(string word) {
        Trie* cur=this;
        for (int i=0; i<word.length(); i++) {
            int idx=word[i]-'a';
            if (!cur->next[idx]) return false;
            cur=cur->next[idx];
        }
        return cur->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur=this;
        for (int i=0; i<prefix.length(); i++) {
            int idx=prefix[i]-'a';
            if (!cur->next[idx]) return false;
            cur=cur->next[idx];
        }
        return true;
    }
};
