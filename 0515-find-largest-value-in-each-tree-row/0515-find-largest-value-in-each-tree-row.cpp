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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }
        
        vector<int> ans;
        stack<pair<TreeNode*, int>> stack;
        stack.push(make_pair(root, 0));
        
        while (!stack.empty()) {
            pair<TreeNode*, int> pair = stack.top();
            stack.pop();
            TreeNode* node = pair.first;
            int depth = pair.second;
            
            if (depth == ans.size()) {
                ans.push_back(node->val);
            } else {
                ans[depth] = max(ans[depth], node->val);
            }
            
            if (node->left) {
                stack.push(make_pair(node->left, depth + 1));
            }
            
            if (node->right) {
                stack.push(make_pair(node->right, depth + 1));
            }
        }
        
        return ans;
    }
};