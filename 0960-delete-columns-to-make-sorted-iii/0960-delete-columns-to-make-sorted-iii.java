public class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int m = strs[0].length();
        int[] dp = new int[m];
        
        // Initialize dp array with 1
        for (int i = 0; i < m; i++) {
            dp[i] = 1;
        }
        
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                // Check if column j is greater than column k for all strings
                if (isSorted(strs, k, j)) {
                    dp[j] = Math.max(dp[j], dp[k] + 1);
                }
            }
        }
        
        // Find the maximum value in dp
        int max = dp[0];
        for (int i = 1; i < m; i++) {
            max = Math.max(max, dp[i]);
        }
        
        // Return the minimum number of columns to delete
        return m - max;
    }
    
    private boolean isSorted(String[] strs, int k, int j) {
        for (String str : strs) {
            if (str.charAt(k) > str.charAt(j)) {
                return false;
            }
        }
        return true;
    }
}
