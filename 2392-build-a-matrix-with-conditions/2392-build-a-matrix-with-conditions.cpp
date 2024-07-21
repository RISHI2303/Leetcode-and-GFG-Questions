class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1), order;
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            order.push_back(f);
            n--;
            for (auto v : adj[f]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
        if (n != 0) return {};
        return order;
    }
};