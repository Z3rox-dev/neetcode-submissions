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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        unordered_map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int minCol = INT_MAX, maxCol = INT_MIN;

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();

            columns[col].push_back(node->val);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }

        vector<vector<int>> res(maxCol - minCol + 1);
        for (int c = minCol; c <= maxCol; c++) {
            res[c - minCol] = columns[c];
        }
        return res;
    }
};
