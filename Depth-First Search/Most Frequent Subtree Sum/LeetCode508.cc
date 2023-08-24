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
    unordered_map<int, int> cnt;
    int maxCnt;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;
        for(auto& [s,c] : cnt)
        {
            if(c == maxCnt)
                ans.push_back(s);
        }

        return ans;
    }

    int dfs(TreeNode* root)
    {
        if(!root) return 0;

        int sum = root->val + dfs(root->left) + dfs(root->right);
        maxCnt = max(maxCnt,++cnt[sum]);

        return sum;
    }
};
