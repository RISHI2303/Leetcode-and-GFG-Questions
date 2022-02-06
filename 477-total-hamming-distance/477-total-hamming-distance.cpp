class Solution {
public:
    // Intuition -> in this function, we are ANDing every number bit-by-bit starting from LSB. If the bit is different, we are increasing the count of set bit by 1. No of offBits i.e. 0 bits can be calculated by the difference of total array length by setBitCount. Now, we are just multiplying the setBitCount and offSetBitCount and adding the result to our final ans. This work is done in O(32*n) time complexity.

int totalHammingDistance(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
    
        int ans = 0;
    
        for (int i = 0; i < 32; i++) { // since we have only 32-bit integers
            int setBitCount = 0;
    
            for (int j = 0; j < nums.size(); j++) { // ANDing every element bit-by-bit and increasing the setBitCount by 1 if the bit is 1 starting from LSB.
                if(nums[j] & (1 << i))
                    setBitCount++;
            }
    
            ans += setBitCount * (nums.size() - setBitCount);
            
        }
    
        return ans;
        
    }
};