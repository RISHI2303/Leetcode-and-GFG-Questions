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
    void dfs(TreeNode* node, int level, vector<int>& sumOfNodesAtLevel) {
        if (node == nullptr) {
            return;
        }

        if (sumOfNodesAtLevel.size() == level) {
            sumOfNodesAtLevel.push_back(node->val);
        } else {
            sumOfNodesAtLevel[level] += node->val;
        }

        dfs(node->left, level + 1, sumOfNodesAtLevel);
        dfs(node->right, level + 1, sumOfNodesAtLevel);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> sumOfNodesAtLevel;
        dfs(root, 0, sumOfNodesAtLevel);

        int maxSum = INT_MIN;
        int ans = 0;

        for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
            if (maxSum < sumOfNodesAtLevel[i]) {
                maxSum = sumOfNodesAtLevel[i];
                ans = i + 1;
            }
        }

        return ans;
    }
};