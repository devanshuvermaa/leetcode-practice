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

    bool helper(TreeNode* root, int target, int count){
        if(root == NULL) return false;

        count += root->val;
        if(root->left == NULL && root->right == NULL){
            if(count == target) return true;
            return false;
        }

        return helper(root->left,target,count) || helper(root->right,target,count);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int count = 0;
        return helper(root,targetSum,count);
        
    }
};