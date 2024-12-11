class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        for (int num : nums) maxValue = max(maxValue, num);

        vector<int> count(maxValue + 1, 0);
        
        for (int num : nums) {
            count[max(num - k, 0)]++;
            if (num + k + 1 <= maxValue)
                count[num + k + 1]--; 
        }

        int currentSum = 0; 
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};