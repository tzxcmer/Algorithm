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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root,path);

        return ans;
    }
    void dfs(TreeNode* root,string path)
    {
        if(!root->left && !root->right)
        {
            path += to_string(root->val);
            ans.push_back(path);
        }
        path += to_string(root->val) + "->";
        if(root->left)
        dfs(root->left,path);
        if(root->right)
        dfs(root->right,path);
        
        return ;
    }
};
