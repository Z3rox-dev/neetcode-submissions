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
    int count = 0;
    void dfs(TreeNode* root, int cur){
        if(root == nullptr) return;

        if(root->val >= cur){
            count++;
        }
        cur = max(cur, root->val);
        dfs(root->left, cur);
        dfs(root->right, cur);
            
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, INT_MIN);
        return count;
    }
};
