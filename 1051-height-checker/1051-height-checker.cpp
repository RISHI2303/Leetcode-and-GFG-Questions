class Solution {
    void bucketSort(vector<int>& arr, int placeValue) {
        vector<vector<int>> buckets(10, vector<int>());
        for (int& val : arr) {
            int digit = abs(val) / placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }
        
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int& val : buckets[digit]) {
                arr[index] = val;
                index++;
            }
        }
    }

    void radixSort(vector<int>& arr) {
        int maxElement = arr[0];
        for (int& val : arr) {
            maxElement = max(abs(val), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        radixSort(sortedHeights);

        int count = 0;
        for (int i = 0; i < sortedHeights.size(); ++i) {
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        return count;
    }
};