/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<NodeVisitPair> nodeStack;
        nodeStack.push(NodeVisitPair(root, false));

        while (!nodeStack.empty()) {
            NodeVisitPair currentPair = nodeStack.top();
            nodeStack.pop();

            if (currentPair.isVisited) {
                result.push_back(currentPair.node->val);
            } else {
                currentPair.isVisited = true;
                nodeStack.push(currentPair);

                vector<Node*>& children = currentPair.node->children;
                for (int i = children.size() - 1; i >= 0; i--) {
                    nodeStack.push(NodeVisitPair(children[i], false));
                }
            }
        }

        return result;
    }

private:
    struct NodeVisitPair {
        Node* node;
        bool isVisited;

        NodeVisitPair(Node* n, bool visited) : node(n), isVisited(visited) {}
    };
};