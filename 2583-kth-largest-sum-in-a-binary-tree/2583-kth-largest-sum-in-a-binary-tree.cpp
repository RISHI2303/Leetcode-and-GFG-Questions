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
    long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long, vector<long>, greater<long> > pq;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* poppedNode = bfsQueue.front();
                bfsQueue.pop();
                sum += poppedNode->val;
                if (poppedNode->left != NULL) {
                    bfsQueue.push(poppedNode->left);
                }
                if (poppedNode->right != NULL) {
                    bfsQueue.push(poppedNode->right);
                }
            }
            pq.push(sum);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        if (pq.size() < k) return -1;
        return pq.top();
    }
};