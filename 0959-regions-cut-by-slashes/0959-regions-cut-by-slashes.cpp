class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        vector<vector<int>> expandedGrid(gridSize * 3,
                                         vector<int>(gridSize * 3, 0));

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                int baseRow = i * 3;
                int baseCol = j * 3;
                if (grid[i][j] == '\\') {
                    expandedGrid[baseRow][baseCol] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol + 2] = 1;
                } else if (grid[i][j] == '/') {
                    expandedGrid[baseRow][baseCol + 2] = 1;
                    expandedGrid[baseRow + 1][baseCol + 1] = 1;
                    expandedGrid[baseRow + 2][baseCol] = 1;
                }
            }
        }

        int regionCount = 0;
        for (int i = 0; i < gridSize * 3; i++) {
            for (int j = 0; j < gridSize * 3; j++) {
                if (expandedGrid[i][j] == 0) {
                    floodFill(expandedGrid, i, j);
                    regionCount++;
                }
            }
        }
        return regionCount;
    }

private:
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void floodFill(vector<vector<int>>& expandedGrid, int row, int col) {
        queue<pair<int, int>> q;
        expandedGrid[row][col] = 1;
        q.push({row, col});

        while (!q.empty()) {
            auto [currentRow, currentCol] = q.front();
            q.pop();
            for (const auto& direction : DIRECTIONS) {
                int newRow = direction[0] + currentRow;
                int newCol = direction[1] + currentCol;
                if (isValidCell(expandedGrid, newRow, newCol)) {
                    expandedGrid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    bool isValidCell(const vector<vector<int>>& expandedGrid, int row,
                     int col) {
        int n = expandedGrid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               expandedGrid[row][col] == 0;
    }
};