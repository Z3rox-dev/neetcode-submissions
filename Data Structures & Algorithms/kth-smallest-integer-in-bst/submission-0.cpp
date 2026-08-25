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
    priority_queue<int> pq;

    void bst(TreeNode* root, int k){
        if(root == nullptr) return;
        pq.push(root->val);
        bst(root->left, k);
        
        if(pq.size() > k){
            pq.pop();
        }
        bst(root->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        bst(root, k);

        return pq.top();
    }
};
