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

    bool isValid(TreeNode* root, int maxValue, int minValue){
        if(root == nullptr){
            return true;
        }
        if((root->val <= minValue) || (root->val >= maxValue)){
            return false;
        }

        return isValid(root->left, root->val, minValue) && isValid(root->right, maxValue, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MAX, INT_MIN);
    }
};