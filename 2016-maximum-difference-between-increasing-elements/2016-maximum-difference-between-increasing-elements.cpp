class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minEle = nums[0], maxDiff = nums[1] - nums[0];
    
        for(int i=1; i<nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i]-minEle);
            minEle = min(minEle, nums[i]);
        }
    
        if(maxDiff > 0)
            return maxDiff;
    
        return -1;
    }
};