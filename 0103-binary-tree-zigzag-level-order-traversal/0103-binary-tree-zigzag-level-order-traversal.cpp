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

    void bfs(TreeNode* root, vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(root);
        
        bool ltordir = true;

        while(!q.empty()){
            int sz = q.size();
            vector<int> temp(sz);
            
            for(int i=0 ; i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(ltordir){
                    temp[i] = curr->val;
                }else{
                    temp[sz-1-i] = curr->val;
                }

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            ans.push_back(temp);
            ltordir = !ltordir;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        bfs(root, ans);

        return ans;
    }
};