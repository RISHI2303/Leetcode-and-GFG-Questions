class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        int currRowNegativeIndex = n - 1;

        for (auto& row : grid) {
            while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0) {
                currRowNegativeIndex--;
            }
            count += (n - (currRowNegativeIndex + 1));
        }
        return count;
    }
};