class Solution {
public:
    int sum = 0; 
    void dfs(TreeNode* root)
    {
        if(root)
        {
            dfs(root->right);
            sum += root->val;
            root->val = sum;
            dfs(root->left);
        }
        return ;
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};
