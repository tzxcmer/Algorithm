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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        int sum = 0;
        sum += dfs(root,targetSum);
        sum += pathSum(root->left,targetSum);
        sum += pathSum(root->right,targetSum);
        return sum;
    }

    int dfs(TreeNode* root, long path)
    {
        if(!root)
            return 0;
        int ret = 0;
        if(root->val == path)
            ret++;
        ret += dfs(root->left,path - root->val);
        ret += dfs(root->right,path - root->val);
        return ret;
    }
};
