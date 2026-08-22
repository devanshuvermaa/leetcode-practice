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

    void dfs(TreeNode* root, int hd,int level, map<int,vector<pair<int ,int>>> &mp){
        if(root == NULL){
            return;
        }
        mp[hd].push_back({level,root->val});

        dfs(root->left,hd-1,level+1,mp);
        dfs(root->right,hd+1,level+1,mp);
    }
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp; // hd, pair={level,node->val}

        dfs(root,0,0,mp);

        vector<vector<int>> ans;
        for(auto p : mp){
            vector<int> temp;
            auto list = p.second;
            sort(list.begin(),list.end());
            for(auto l : list){
                temp.push_back(l.second);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};