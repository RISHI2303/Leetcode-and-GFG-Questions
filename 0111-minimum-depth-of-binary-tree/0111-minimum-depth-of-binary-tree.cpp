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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        
        while (!q.empty()) {
            int qSize = q.size();
            
            while (qSize--) {
                TreeNode* node = q.front(); q.pop();
                // Since we added nodes without checking null, we need to skip them here.
                if (!node) {
                    continue;
                }
                
                // The first leaf would be at minimum depth, hence return it.
                if (!node->left && !node->right) {
                    return depth;
                }
                
                q.push({node->left});
                q.push({node->right});
            }
            
            depth++;
        }
        return -1;
    }
};