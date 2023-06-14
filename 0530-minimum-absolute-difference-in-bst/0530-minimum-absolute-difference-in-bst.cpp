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
    int minDifference = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevNode;
        
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        inorderTraversal(node->left);
        // Find the difference with the previous value if it is there.
        if (prevNode != NULL) {
            minDifference = min(minDifference, node->val - prevNode->val);
        }
        prevNode = node;
        inorderTraversal(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDifference;
    }
};