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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        TreeNode dummy = -1;
        TreeNode* dummyNode = &dummy;
        TreeNode* predecessor = NULL;
        dummyNode->left = root;
        root = dummyNode;

        while (root != NULL) {
            if (root->left != NULL) {
                predecessor = root->left;

                while (predecessor->right != NULL &&
                       predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == NULL) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    TreeNode* node = predecessor;
                    reverseSubtreeLinks(root->left, predecessor);

                    while (node != root->left) {
                        result.push_back(node->val);
                        node = node->right;
                    }

                    result.push_back(node->val);
                    reverseSubtreeLinks(predecessor, root->left);
                    predecessor->right = NULL;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }

        return result;
    }

    void reverseSubtreeLinks(TreeNode* startNode, TreeNode* endNode) {
        if (startNode == endNode) {
            return;
        }

        TreeNode* prev = NULL;
        TreeNode* current = startNode;
        TreeNode* next = NULL;

        while (current != endNode) {
            next = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }

        current->right = prev;
    }
};