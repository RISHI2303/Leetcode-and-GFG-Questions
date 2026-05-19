public class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return getCommon(nums2, nums1);
        }
        
        for (int num : nums1) {
            if (binarySearch(num, nums2)) {
                return num;
            }
        }
        return -1;
    }

    private boolean binarySearch(int target, int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
}