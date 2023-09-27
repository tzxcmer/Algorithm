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
    int maxsum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }

    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        int lsum = max(dfs(root->left),0);
        int rsum = max(dfs(root->right),0);

        int sum = root->val + lsum + rsum;

        maxsum = max(maxsum,sum);

        return root->val + max(lsum,rsum);
    }
};
