class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxDistance = 0;

        for(int i = 1; i < arrays.size(); i++) {
            // Calculate distance using current min and max with other arrays
            maxDistance = max(maxDistance, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i][0])));

            // Update the global min and max values
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDistance;
    }
};

