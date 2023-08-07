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
    int ret = -1;
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        dfs(root,cnt);
        return ret;
    }
    void dfs(TreeNode* root, int k)
    {
        if(!root || cnt == 0)
            return ;
        dfs(root->left,cnt);
        if(cnt != 0)
            cnt--;
        if(cnt == 0 && ret == -1)
            ret = root->val;
        dfs(root->right,cnt);

        return ;
    }
};
