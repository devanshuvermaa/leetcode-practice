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

    void helper(TreeNode* root, int target, long long currsum, int &count,unordered_map<long long,int> &prefixsum){
        if(root == NULL) return;

        currsum += root->val;
        if(prefixsum.count(currsum-target)){
            count += prefixsum[currsum-target];
        }
        prefixsum[currsum]++;
        helper(root->left,target,currsum,count,prefixsum);
        helper(root->right,target,currsum,count,prefixsum);

        prefixsum[currsum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> prefixsum;
        prefixsum[0]=1;
        int count = 0;
        helper(root,targetSum,0,count,prefixsum);
        return count;
    }
};