class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = {};
        }

        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[from].push_back(to);
            indegree[to]++;
        }

        queue<int> nodesWithZeroIndegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                nodesWithZeroIndegree.push(i);
            }
        }

        vector<int> topologicalOrder;
        while (!nodesWithZeroIndegree.empty()) {
            int currentNode = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            topologicalOrder.push_back(currentNode);

            for (int neighbor : adjacencyList[currentNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    nodesWithZeroIndegree.push(neighbor);
                }
            }
        }

        vector<vector<int>> ancestorsList(n);
        vector<set<int>> ancestorsSetList(n);

        for (int node : topologicalOrder) {
            for (int neighbor : adjacencyList[node]) {
                ancestorsSetList[neighbor].insert(node);
                ancestorsSetList[neighbor].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        for (int i = 0; i < ancestorsList.size(); i++) {
            ancestorsList[i].assign(ancestorsSetList[i].begin(),
                                    ancestorsSetList[i].end());
            sort(ancestorsList[i].begin(), ancestorsList[i].end());
        }

        return ancestorsList;
    }
};