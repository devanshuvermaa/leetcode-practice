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
class BSTIterator {
    stack<TreeNode*> s;
    bool isreverse;
    void pushall(TreeNode* root) {
        while (root != NULL) {
            s.push(root);
            if (isreverse) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverse) {
        isreverse = reverse;
        pushall(root);
    }

    int next() {
        TreeNode* curr = s.top();
        s.pop();

        if (isreverse) {
            pushall(curr->left);
        } else {
            pushall(curr->right);
        }

        return curr->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k)
                return true;
            if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};