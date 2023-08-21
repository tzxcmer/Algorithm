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
    unordered_map<string, TreeNode*> mt;
    unordered_set<TreeNode*> st;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);

        return {st.begin(),st.end()};
    }

    string dfs(TreeNode* root)
    {
        if(!root)
            return "";
        string str;
        str += to_string(root->val)+"("+dfs(root->left)+")"
        +"("+dfs(root->right)+")";
        if(auto it = mt.find(str);it != mt.end())
            st.insert(it->second);
        else
            mt[str] = root;
        
        return str;
    }
};
