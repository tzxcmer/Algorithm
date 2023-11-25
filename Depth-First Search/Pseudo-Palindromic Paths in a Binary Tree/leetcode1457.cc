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
    int dfs(TreeNode* root, vector<int>& cnt)
    {
        if(!root) return 0;
        cnt[root->val]++;
        int res = 0;
        if(!root->left && !root->right)
        {
            if(ispa(cnt))
                res = 1;
        }
        else
            res = dfs(root->left,cnt) + dfs(root->right,cnt);
        
        cnt[root->val]--;
        return res;
    } 

    bool ispa(vector<int>& cnt)
    {
        int odd = 0;
        for(auto num : cnt)
        {
            if(num %2 == 1)
                odd++;
        }

        return odd <= 1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10);
        return dfs(root,cnt);
    }
};
