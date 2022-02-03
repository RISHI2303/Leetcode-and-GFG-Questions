class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt = 0;
    
        // to stores frequencies of all possible nums[i] & nums[j]
        unordered_map<int, int> m;
    
        for (auto i: nums)
            for (auto j: nums) // this will update frequency of Bitwise AND of all array elements with a
			    m[i & j]++;

        for (auto i: nums)
            for (auto j: m)
                if ((j.first & i) == 0) // If bitwise AND of triplet is zero, increment cnt
		    		cnt += j.second;
	    return cnt;
    }
};