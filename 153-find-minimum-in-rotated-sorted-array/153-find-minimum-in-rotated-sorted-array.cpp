class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
    
        while(low <= high) {
            if(nums[low] <= nums[high])
                return nums[low];
    
            int mid = (low + high)/2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1 + n) % n;
    
            if(nums[mid] < nums[next] && nums[mid] < nums[prev])
                return nums[mid];
    
            else if(nums[mid] < nums[high])
                high = mid - 1;
    
            else
                low = mid + 1;
        }
    
        return 0;
    }
};