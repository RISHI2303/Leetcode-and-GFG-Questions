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
    int rangeSumBST(TreeNode* root, int L, int H) {
        int ans = 0;
        while(root) 
            if(root -> left && root -> val >= L) {
                auto pre = root -> left;  
                // find predecessor of root
                while(pre -> right && pre -> right != root)  pre = pre -> right;
                // make root as right child of predecessor (temporary link)
                if(!pre -> right) {
                    pre -> right = root;
                    root = root -> left;                    
                }
                else {                    
                    if(root -> val >= L && root -> val <= H) ans += root -> val;
                    pre -> right = nullptr;  // revert the changes - remove temporary link
                    root = root -> right;
                }
            } 
			else {
                if(root -> val >= L && root -> val <= H) ans += root -> val;
                root = root -> right;
            }
        
        return ans;
    }
};