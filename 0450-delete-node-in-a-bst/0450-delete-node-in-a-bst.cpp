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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            if(root->left == NULL || root->right == NULL ){
                return (root->left==NULL) ? root->right : root->left;
            }

            TreeNode* IS = root->right;
            while(IS->left != NULL){
                IS = IS->left;
            }
            root->val = IS->val;

            root-> right = deleteNode(root->right,root->val);
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        
        return root;
    }
};