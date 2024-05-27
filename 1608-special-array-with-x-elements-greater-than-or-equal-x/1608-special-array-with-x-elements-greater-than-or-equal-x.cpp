class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++) {
            freq[min(N, nums[i])]++;
        }
        
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual) {
                return i;
            }
        }
        
        return -1;
    }
};