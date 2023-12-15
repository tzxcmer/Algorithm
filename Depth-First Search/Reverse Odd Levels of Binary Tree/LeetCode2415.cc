class Solution {
public:
    void dfs(TreeNode* r1,TreeNode*r2,bool isodd)
    {
        if(!r1) return ;
        if(isodd) swap(r1->val,r2->val);

        dfs(r1->left,r2->right,!isodd);
        dfs(r1->right,r2->left,!isodd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);

        return root;
    }
};
