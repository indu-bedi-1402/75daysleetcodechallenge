class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    vector<string> ans;

    void insert(TrieNode* root, string word) {
        TrieNode* temp = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (temp->child[idx] == NULL)
                temp->child[idx] = new TrieNode();

            temp = temp->child[idx];
        }

        temp->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char ch = board[i][j];

        if (ch == '#' || node->child[ch - 'a'] == NULL)
            return;

        node = node->child[ch - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < rows && nj < cols) {
                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string word : words)
            insert(root, word);

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};