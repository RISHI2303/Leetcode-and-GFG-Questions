class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0, n = nums.size();
        unordered_map <int, int> m;

        for(int i=0; i<n; i++)
            m[nums[i]]++;

        for(auto i: m) {
            if(i.second > 1)
                count += (i.second*(i.second - 1))/2;
        }

        return count;
    }
};