class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        n = amount.size();
        tree.resize(n, vector<int>());

        for (vector<int> edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        distanceFromBob.resize(n);
        return findPaths(0, 0, 0, bob, amount);
    }

private:
    vector<vector<int>> tree;
    vector<int> distanceFromBob;
    int n;

    int findPaths(int sourceNode, int parentNode, int time, int bob,
                  vector<int>& amount) {
        int maxIncome = 0, maxChild = INT_MIN;

        if (sourceNode == bob)
            distanceFromBob[sourceNode] = 0;
        else
            distanceFromBob[sourceNode] = n;
        for (int adjacentNode : tree[sourceNode]) {
            if (adjacentNode != parentNode) {
                maxChild = max(maxChild, findPaths(adjacentNode, sourceNode,
                                                   time + 1, bob, amount));
                distanceFromBob[sourceNode] =
                    min(distanceFromBob[sourceNode],
                        distanceFromBob[adjacentNode] + 1);
            }
        }
        if (distanceFromBob[sourceNode] > time) maxIncome += amount[sourceNode];

        else if (distanceFromBob[sourceNode] == time)
            maxIncome += amount[sourceNode] / 2;

        if (maxChild == INT_MIN)
            return maxIncome;
        else
            return maxIncome + maxChild;
    }
};