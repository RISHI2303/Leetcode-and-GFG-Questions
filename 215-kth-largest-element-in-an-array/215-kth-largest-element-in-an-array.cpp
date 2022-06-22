class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k; // convert to index of k largest
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int i = l; // partition [l,r] by nums[l]: [l,i]<nums[l], [i+1,j)>=nums[l]
            for (int j = l + 1; j <= r; j++)
                if (nums[j] < nums[l]) 
                    swap(nums[j], nums[i]);
            swap(nums[l], nums[i]);

            if (k < i) 
                r = i - 1;
            else if (k > i)
                l = i + 1;
            else return 
                nums[i];
        }
        return -1; // k is invalid
    }
};