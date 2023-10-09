class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1, ans = -1;
        vector <int> v;
    
        // for first
        while(low <= high) {
            int mid = (low + high)/2;
    
            if(nums[mid] > target)
                high = mid - 1;
            
            else if (nums[mid] < target)
                low = mid + 1;
    
            else {
                ans = mid;
                high = mid - 1;
            }
        }
    
        v.push_back(ans);
    
        ans = -1;
        low = 0;
        high = n - 1;
    
        // for last
        while(low <= high) {
            int mid = (low + high)/2;
    
            if(nums[mid] > target)
                high = mid - 1;
            
            else if (nums[mid] < target)
                low = mid + 1;
    
            else {
                ans = mid;
                low = mid + 1;
            }
        }
    
        v.push_back(ans);
    
        return v;
    }
};