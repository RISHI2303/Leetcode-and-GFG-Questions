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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> levels;
        int index = 0, n = traversal.size();

        while (index < n) {
            int depth = 0;
            while (index < n && traversal[index] == '-') {
                depth++;
                index++;
            }

            int value = 0;
            while (index < n && isdigit(traversal[index])) {
                value = value * 10 + (traversal[index] - '0');
                index++;
            }

            TreeNode* node = new TreeNode(value);

            if (depth < levels.size()) {
                levels[depth] = node;
            } else {
                levels.push_back(node);
            }

            if (depth > 0) {
                TreeNode* parent = levels[depth - 1];
                if (parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }

        return levels[0];
    }
};