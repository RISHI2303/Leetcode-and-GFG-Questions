class Solution {
public:
    int mod = 1000000007;
    int kow[51][51][51];
    long solve(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow >= m or startRow < 0 or startColumn >= n or startColumn < 0){
            return 1;
        }
        if(maxMove <= 0){
            return 0;
        }
        if(kow[startRow][startColumn][maxMove] != -1){
            return kow[startRow][startColumn][maxMove];
        }
        long count = 0;
        count += solve(m, n, maxMove - 1, startRow - 1, startColumn);
        count += solve(m, n, maxMove - 1, startRow, startColumn + 1);
        count += solve(m, n, maxMove - 1, startRow + 1, startColumn);
        count += solve(m, n, maxMove - 1, startRow, startColumn - 1);
        return kow[startRow][startColumn][maxMove] = count%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(kow, -1, sizeof(kow));
        return solve(m, n, maxMove, startRow, startColumn)%mod;
    }
};