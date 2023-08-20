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
    bool checkTree(TreeNode* root) {
        int suml = dfs(root->left);
        int sumr = dfs(root->right);
        int sum = root->val;
        if(sum == suml + sumr)
        {
            return true;
        }
        return false;
    }

    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        return root->val + dfs(root->left) + dfs(root->right);
    }
};
