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
    int sumNumbers(TreeNode* root) {
         return dfs(root,0);
    }
    int dfs(TreeNode* root, int presum)
    {
        int sum = presum*10+root->val;
        if(!root->left && !root->right)
            return sum;
        int ret = 0;
        if(root->left)
            ret += dfs(root->left,sum);
        if(root->right)
            ret += dfs(root->right,sum);
        sum = ret;
        return sum;
    }
};
