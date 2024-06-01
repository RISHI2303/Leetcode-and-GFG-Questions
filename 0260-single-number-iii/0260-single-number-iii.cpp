class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int firstXorSec = 0, mask = 1, first = 0;
        for (auto &num: nums) 
            firstXorSec ^= num;
        while (not (firstXorSec & mask)) 
            mask <<= 1;
        for (auto &num: nums)
            if (num & mask) 
                first ^= num;
        return {first, firstXorSec ^ first};
    }
};