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
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool l = isValidBST(root->left);
        bool cur = false;
        if(prev < root->val)
            cur = true;
        prev = root->val;
        bool r = isValidBST(root->right);

        return l && r && cur;
    }
};
