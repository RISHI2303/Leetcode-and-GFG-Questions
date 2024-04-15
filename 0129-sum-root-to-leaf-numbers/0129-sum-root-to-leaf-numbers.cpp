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
    int sumNumbers(TreeNode* root) {
        int sum = 0, cur = 0, depth = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;
                depth = 1;
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right, depth++;
                if(!pre -> right) {
                    pre -> right = root;
                    cur = cur * 10 + root -> val;
                    root = root -> left;
                } else {
                    pre -> right = nullptr;
                    if(!pre -> left) sum += cur;
                    cur /= pow(10, depth);
                    root = root -> right;
                }
            } else {
                cur = cur * 10 + root -> val;
                if(!root -> right) sum += cur;
                root = root -> right;
            }
        }
        return sum;
    }
};