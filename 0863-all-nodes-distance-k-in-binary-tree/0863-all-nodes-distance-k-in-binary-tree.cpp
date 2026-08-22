/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<TreeNode*> &vec){
        if(root == NULL) return;

        if(root->left != NULL) {
            vec[root->left->val] = root;
        }
        if(root->right != NULL){
            vec[root->right->val] = root;
        }

        dfs(root->left,vec);
        dfs(root->right,vec);
    }
    vector<int> helper(TreeNode* root,int k,vector<TreeNode*> &vec){
        vector<int> ans;
        vector<bool> vis(501,false);
        queue<TreeNode*> q;
        q.push(root);
        vis[root->val] = true;
        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i =0 ;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(level == k){
                    ans.push_back(curr->val);
                }
                if(curr->left != NULL && !vis[curr->left->val]){
                    vis[curr->left->val] = true;
                    q.push(curr->left);
                }
                if(curr->right != NULL && !vis[curr->right->val]){
                    vis[curr->right->val] = true;
                    q.push(curr->right);
                }
                if(vec[curr->val] != NULL && vis[vec[curr->val]->val] == false) {
                    vis[vec[curr->val]->val] = true;
                    q.push(vec[curr->val]);
                }
            }
            if(level == k){
                return ans;
            }
            level++;
        } 
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> vec(501,NULL);
        dfs(root,vec);
        return helper(target,k,vec);
    }
};