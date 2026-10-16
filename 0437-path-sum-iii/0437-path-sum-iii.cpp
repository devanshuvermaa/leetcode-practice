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

    void helper(TreeNode* root, int target, long long sum, int &count){
        if(root == NULL) return;

        sum += root->val;
        if(sum == target) count++;

        helper(root->left,target,sum,count);
        helper(root->right,target,sum,count);
    }
    void dfs(TreeNode* root, int target, int &count){
        if(root == NULL){
            return;
        }
        helper(root,target,0,count);
        dfs(root->left,target,count);
        dfs(root->right,target,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfs(root,targetSum,count);
        return count;
    }
};