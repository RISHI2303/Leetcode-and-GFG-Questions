class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int arraySize = nums.size();

        int low = 0;
        int high = nums[arraySize - 1] - nums[0];

        while (low < high) {
            int mid = (low + high) / 2;

            int count = countPairsWithMaxDistance(nums, mid);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

private:
    int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
        int count = 0;
        int arraySize = nums.size();
        int left = 0;

        for (int right = 0; right < arraySize; ++right) {
            while (nums[right] - nums[left] > maxDistance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};