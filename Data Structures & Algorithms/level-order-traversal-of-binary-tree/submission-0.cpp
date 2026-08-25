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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::deque<TreeNode*> depthValues;
        if(root == nullptr){
            return {};
        }
        depthValues.push_back(root);
        std::vector<std::vector<int>> ans;
        std::vector<int> cycleVec;

        while(!depthValues.empty()){
            int size = depthValues.size();

            for(int i = 0; i < size; i++){
                TreeNode* node = depthValues.front();
                int value = node->val;
                depthValues.pop_front();
                cycleVec.push_back(value);

                if(node->left != nullptr){
                    depthValues.push_back(node->left);
                }
                if(node->right != nullptr){
                    depthValues.push_back(node->right);
                }
            }
            ans.push_back(cycleVec);
            cycleVec.clear();
        }
        return ans;
    }
};
