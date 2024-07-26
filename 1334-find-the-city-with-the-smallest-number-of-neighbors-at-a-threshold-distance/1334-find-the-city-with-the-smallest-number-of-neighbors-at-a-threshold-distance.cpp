class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9 + 7;
        vector<vector<int>> distanceMatrix(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            distanceMatrix[i][i] = 0;
        }

        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distanceMatrix[start][end] = weight;
            distanceMatrix[end][start] = weight; 
        }

        floyd(n, distanceMatrix);

        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

    void floyd(int n, vector<vector<int>>& distanceMatrix) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distanceMatrix[i][j] =
                        min(distanceMatrix[i][j],
                            distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }
    }

    int getCityWithFewestReachable(int n,
                                   const vector<vector<int>>& distanceMatrix,
                                   int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }  
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};