class Solution {
private:
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct ArticulationPointInfo {
        bool hasArticulationPoint;
        int time;

        ArticulationPointInfo(bool hasArticulationPoint, int time)
            : hasArticulationPoint(hasArticulationPoint), time(time) {}
    };

public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        ArticulationPointInfo apInfo(false, 0);
        int landCells = 0, islandCount = 0;

        vector<vector<int>> discoveryTime(
            rows,
            vector<int>(cols, -1)); 
        vector<vector<int>> lowestReachable(
            rows,
            vector<int>(cols, -1));
        vector<vector<int>> parentCell(
            rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    landCells++;
                    if (discoveryTime[i][j] == -1) {
                        findArticulationPoints(grid, i, j, discoveryTime,
                                               lowestReachable, parentCell,
                                               apInfo);
                        islandCount++;
                    }
                }
            }
        }

        if (islandCount == 0 || islandCount >= 2)
            return 0; 
        if (landCells == 1) return 1; 
        if (apInfo.hasArticulationPoint)
            return 1;
        return 2; 
    }

private:
    void findArticulationPoints(vector<vector<int>>& grid, int row, int col,
                                vector<vector<int>>& discoveryTime,
                                vector<vector<int>>& lowestReachable,
                                vector<vector<int>>& parentCell,
                                ArticulationPointInfo& apInfo) {
        int rows = grid.size(), cols = grid[0].size();
        discoveryTime[row][col] = apInfo.time;
        apInfo.time++;
        lowestReachable[row][col] = discoveryTime[row][col];
        int children = 0;

        for (const auto& direction : DIRECTIONS) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (isValidLandCell(grid, newRow, newCol)) {
                if (discoveryTime[newRow][newCol] == -1) {
                    children++;
                    parentCell[newRow][newCol] =
                        row * cols + col;
                    findArticulationPoints(grid, newRow, newCol, discoveryTime,
                                           lowestReachable, parentCell, apInfo);

                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            lowestReachable[newRow][newCol]);

                    if (lowestReachable[newRow][newCol] >=
                            discoveryTime[row][col] &&
                        parentCell[row][col] != -1) {
                        apInfo.hasArticulationPoint = true;
                    }
                } else if (newRow * cols + newCol != parentCell[row][col]) {
                    lowestReachable[row][col] =
                        min(lowestReachable[row][col],
                            discoveryTime[newRow][newCol]);
                }
            }
        }

        if (parentCell[row][col] == -1 && children > 1) {
            apInfo.hasArticulationPoint = true;
        }
    }

    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        return row >= 0 && col >= 0 && row < rows && col < cols &&
               grid[row][col] == 1;
    }
};