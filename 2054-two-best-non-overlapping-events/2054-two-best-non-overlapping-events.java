class Solution {
    public int maxTwoEvents(int[][] activityList) {
        int n = activityList.length;

        // Step 1: Sort activities based on their start times
        Arrays.sort(activityList, (a, b) -> Integer.compare(a[0], b[0]));

        // Step 2: Create a suffix max array to store the best value from index i to n-1
        int[] suffixMaxValues = new int[n];
        suffixMaxValues[n - 1] = activityList[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMaxValues[i] = Math.max(activityList[i][2], suffixMaxValues[i + 1]);
        }

        int maxTotalProfit = 0;

        for (int i = 0; i < n; i++) {
            // Case 1: Consider only the current event
            int currentVal = activityList[i][2];
            maxTotalProfit = Math.max(maxTotalProfit, currentVal);

            // Case 2: Try to find a second non-overlapping event
            int finishTime = activityList[i][1];
            int nextEventIdx = findFirstValidEvent(activityList, finishTime);

            if (nextEventIdx != -1) {
                maxTotalProfit = Math.max(maxTotalProfit, currentVal + suffixMaxValues[nextEventIdx]);
            }
        }

        return maxTotalProfit;
    }

    // Binary search to find the first event that starts AFTER the current event's end time
    private int findFirstValidEvent(int[][] activities, int targetEndTime) {
        int low = 0, high = activities.length - 1;
        int resultIdx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (activities[mid][0] > targetEndTime) {
                resultIdx = mid;
                high = mid - 1; // Look for an even earlier start time
            } else {
                low = mid + 1;
            }
        }
        return resultIdx;
    }
}
