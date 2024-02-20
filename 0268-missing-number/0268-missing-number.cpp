class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size(), i = 0;
    
        for(auto j: nums) {
            n ^= j ^ i;
            i++;
        }
    
        return n;
    }
};