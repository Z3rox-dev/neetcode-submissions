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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->left == nullptr) return root;
        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        if(p->val < root->val && q->val < root->val){
            return leftNode;
        }
        if(root->right == nullptr) return root;

        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
        if(p->val > root->val && q->val > root->val){
            return rightNode;
        }
        return root;
    }
};
