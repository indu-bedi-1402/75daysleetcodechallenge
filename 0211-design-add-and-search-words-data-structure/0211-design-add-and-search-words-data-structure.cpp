class WordDictionary {
public:
    
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        
        TrieNode() {
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
            isEnd = false;
        }
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        
        for(char ch : word) {
            int idx = ch - 'a';
            
            if(temp->child[idx] == NULL)
                temp->child[idx] = new TrieNode();
            
            temp = temp->child[idx];
        }
        
        temp->isEnd = true;
    }
    
    bool searchHelper(string word, int pos, TrieNode* node) {
        if(node == NULL) return false;
        
        if(pos == word.length())
            return node->isEnd;
        
        char ch = word[pos];
        
        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(searchHelper(word, pos + 1, node->child[i]))
                    return true;
            }
            return false;
        }
        else {
            int idx = ch - 'a';
            return searchHelper(word, pos + 1, node->child[idx]);
        }
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

