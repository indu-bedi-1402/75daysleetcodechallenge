

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both are NULL
        if (p == NULL && q == NULL)
            return true;

        // Case 2: one is NULL
        if (p == NULL || q == NULL)
            return false;

        // Case 3: values must match + check left & right
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && 
                   isSameTree(p->right, q->right);

        return false;
    }
};