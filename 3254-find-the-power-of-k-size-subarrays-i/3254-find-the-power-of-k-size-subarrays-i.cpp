class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }

        size_t length = nums.size();
        vector<int> result(length - k + 1, -1); 
        int consecutiveCount = 1; 

        for (size_t index = 0; index < length - 1; index++) {
            if (nums[index] + 1 == nums[index + 1]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;  
            }

            if (consecutiveCount >= k) {
                result[index - k + 2] = nums[index + 1];
            }
        }

        return result;
    }
};