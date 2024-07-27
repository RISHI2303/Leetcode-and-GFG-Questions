class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        long long totalCost = 0;

        vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));

        for (int i = 0; i < original.size(); ++i) {
            int startChar = original[i] - 'a';
            int endChar = changed[i] - 'a';
            minCost[startChar][endChar] =
                min(minCost[startChar][endChar], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    minCost[i][j] =
                        min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }

        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if (minCost[sourceChar][targetChar] >= INT_MAX) {
                return -1;
            }
            totalCost += minCost[sourceChar][targetChar];
        }

        return totalCost;
    }
};