class Trie {
public:
    struct Node {
        Node* child[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (temp->child[index] == NULL)
                temp->child[index] = new Node();

            temp = temp->child[index];
        }

        temp->end = true;
    }

    bool search(string word) {
        Node* temp = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (temp->child[index] == NULL)
                return false;

            temp = temp->child[index];
        }

        return temp->end;
    }

    bool startsWith(string prefix) {
        Node* temp = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (temp->child[index] == NULL)
                return false;

            temp = temp->child[index];
        }

        return true;
    }
};
