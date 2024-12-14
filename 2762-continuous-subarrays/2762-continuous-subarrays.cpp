class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int right = 0, left = 0;
        int curMin, curMax;
        long long windowLen = 0, total = 0;

        curMin = curMax = nums[right];

        for (right = 0; right < nums.size(); right++) {
            curMin = min(curMin, nums[right]);
            curMax = max(curMax, nums[right]);

            if (curMax - curMin > 2) {
                windowLen = right - left;
                total += (windowLen * (windowLen + 1) / 2);

                left = right;
                curMin = curMax = nums[right];

                while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    curMin = min(curMin, nums[left]);
                    curMax = max(curMax, nums[left]);
                }

                if (left < right) {
                    windowLen = right - left;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }

        windowLen = right - left;
        total += (windowLen * (windowLen + 1) / 2);

        return total;
    }
};