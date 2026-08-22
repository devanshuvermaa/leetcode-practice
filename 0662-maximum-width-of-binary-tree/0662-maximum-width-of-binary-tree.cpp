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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long maxwid = 0;

        while (!q.empty()) {
            int sz = q.size();
            long long levelmin = q.front().second;
            long long firstidx = 0, lastidx = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front().first;
                long long curridx = q.front().second - levelmin;
                q.pop();

                if (i == 0) {
                    firstidx = curridx;
                }
                if (i == sz - 1) {
                    lastidx = curridx;
                }

                if (curr->left != NULL)
                    q.push({curr->left, 2 * curridx + 1});
                if (curr->right != NULL)
                    q.push({curr->right, 2 * curridx + 2});
            }
            maxwid = max(maxwid, lastidx - firstidx+1);
        }

        return maxwid;
    }
};