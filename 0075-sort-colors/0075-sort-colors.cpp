class Solution {
public:
    void sortColors(vector<int> &nums) {
        int count0 = 0, count1 = 0, count2 = 0, j = 0;
    
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
                count0++;
            if(nums[i] == 1)
                count1++;
            if(nums[i] == 2)
                count2++;
        }
    
        for(int i=0; i<count0; i++)
            nums[j++] = 0;
    
        for(int i=0; i<count1; i++)
            nums[j++] = 1;
    
        for(int i=0; i<count2; i++)
            nums[j++] = 2;
    }
};