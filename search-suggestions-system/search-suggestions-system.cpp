class Solution {
    struct TrieNode {
        char c;
        bool isWord;
        vector<TrieNode*> nodes;

        TrieNode(char& c): c(c), isWord(false), nodes(vector<TrieNode*>(26)) {};
    };

    void getString(TrieNode* node, string& pre, string prev, vector<string>& vec) {
        if (!node || vec.size()==3) return;
        prev += node->c;
        if (node->isWord) {
            vec.push_back(pre + prev);
        }
        for (int i=0; i<26; i++) {
            if (node->nodes[i]) {
                getString(node->nodes[i], pre, prev, vec);
            }
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size());
        TrieNode* root = new TrieNode(searchWord[0]);
        for (string& p : products) {
            if (p[0]!=searchWord[0]) continue;
            TrieNode* cur=root;
            for (int i=1; i<p.length(); ++i) {
                char c=p[i];
                if (!cur->nodes[c-'a']) {
                    cur->nodes[c-'a'] = new TrieNode(c);
                }
                cur=cur->nodes[c-'a'];
            }
            cur->isWord=true;
        }
        string pre="";
        for (int i=0; i<searchWord.length(); ++i) {
            string prev="";
            if (i!=0 && root) root=root->nodes[searchWord[i]-'a'];
            getString(root, pre, prev, ans[i]);
            pre+=searchWord[i];
        }
        return ans;
    }
};