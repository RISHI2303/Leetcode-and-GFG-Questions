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
    
private:
    void rightViewUtil(TreeNode *root, int level, vector<int> &v) {
        if(root == NULL)
            return;
        
        if(v.size() == level)
            v.push_back(root->val);
        
        rightViewUtil(root->right, level + 1, v);
        rightViewUtil(root->left, level + 1, v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v;
        rightViewUtil(root, 0, v);
        return v;
    }
};