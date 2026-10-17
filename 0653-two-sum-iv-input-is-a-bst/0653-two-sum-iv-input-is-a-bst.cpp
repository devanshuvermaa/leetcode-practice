/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTiterator {
    stack<TreeNode*> st;
    bool reverse;
    void pushpath(TreeNode* root) {
        while (root) {
            st.push(root);
            root = reverse ? root->right : root->left;
        }
    }

public:
    BSTiterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        pushpath(root);
    }

    bool hasnext() { return !st.empty(); }

    int next() {
        TreeNode* root = st.top();
        st.pop();

        if (reverse) {
            if (root->left)
                pushpath(root->left);
        } else {
            if (root->right)
                pushpath(root->right);
        }

        return root->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator left(root, false);
        BSTiterator right(root, true);

        int l = left.next();
        int r = right.next();

        while (l < r) {
            if (l + r == k)
                return true;
            if (l + r > k) {
                if (right.hasnext()) {
                    r = right.next();
                }
            }
            else if (l + r < k) {
                if (left.hasnext()) {
                    l = left.next();
                }
            }
        }
        return false;
    }
};