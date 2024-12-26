class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> dp(2 * totalSum + 1, 0);

        dp[nums[0] + totalSum] = 1; 
        dp[-nums[0] + totalSum] += 1;  

        for (int index = 1; index < nums.size(); index++) {
            vector<int> next(2 * totalSum + 1, 0);
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[sum + totalSum] > 0) {
                    next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                    next[sum - nums[index] + totalSum] += dp[sum + totalSum];
                }
            }
            dp = next;
        }

        return abs(target) > totalSum ? 0 : dp[target + totalSum];
    }
};