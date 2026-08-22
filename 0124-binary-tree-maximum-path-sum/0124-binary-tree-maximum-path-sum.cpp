/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* root, int &globalsum){
        if(root == NULL){
            return 0;
        }

        int left = max(0,helper(root->left,globalsum));
        int right = max(0,helper(root->right,globalsum));

        globalsum = max(globalsum,root->val+left+right);

        return (root->val + max(left,right));

    }

    int maxPathSum(TreeNode* root) {
        int globalsum = -1e9;
        helper(root,globalsum);
        return globalsum;
    }
};