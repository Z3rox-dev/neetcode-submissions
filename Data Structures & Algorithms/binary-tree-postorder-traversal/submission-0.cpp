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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* prev = nullptr;
        while(root || !st.empty()){
            TreeNode* cur = root;
            while(cur){
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* node = st.top();

            if(!node->right || prev == node->right){
                res.push_back(node->val);
                st.pop();
                prev = node;
                root = nullptr;
            }
            else{
                root = node->right;
            }
        }
        return res;
    }
};