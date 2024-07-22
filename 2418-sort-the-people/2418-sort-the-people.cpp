class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        mergeSort(names, heights, 0, heights.size() - 1);
        return names;
    }

private:
    void mergeSort(vector<string>& names, vector<int>& heights, int start,
                   int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(names, heights, start, mid);
            mergeSort(names, heights, mid + 1, end);
            merge(names, heights, start, mid, end);
        }
    }

    void merge(vector<string>& names, vector<int>& heights, int start, int mid,
               int end) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        vector<int> leftHeights(leftSize);
        vector<int> rightHeights(rightSize);
        vector<string> leftNames(leftSize);
        vector<string> rightNames(rightSize);

        for (int i = 0; i < leftSize; i++) {
            leftHeights[i] = heights[start + i];
            leftNames[i] = names[start + i];
        }
        for (int j = 0; j < rightSize; j++) {
            rightHeights[j] = heights[mid + 1 + j];
            rightNames[j] = names[mid + 1 + j];
        }

        int leftIndex = 0, rightIndex = 0;
        int mergeIndex = start;
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (leftHeights[leftIndex] >=
                rightHeights[rightIndex]) {  // Descending order
                heights[mergeIndex] = leftHeights[leftIndex];
                names[mergeIndex] = leftNames[leftIndex];
                leftIndex++;
            } else {
                heights[mergeIndex] = rightHeights[rightIndex];
                names[mergeIndex] = rightNames[rightIndex];
                rightIndex++;
            }
            mergeIndex++;
        }

        while (leftIndex < leftSize) {
            heights[mergeIndex] = leftHeights[leftIndex];
            names[mergeIndex] = leftNames[leftIndex];
            leftIndex++;
            mergeIndex++;
        }

        while (rightIndex < rightSize) {
            heights[mergeIndex] = rightHeights[rightIndex];
            names[mergeIndex] = rightNames[rightIndex];
            rightIndex++;
            mergeIndex++;
        }
    }
};