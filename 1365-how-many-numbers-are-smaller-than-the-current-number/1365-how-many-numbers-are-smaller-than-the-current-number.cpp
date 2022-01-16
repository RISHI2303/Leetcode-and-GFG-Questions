class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> v = nums;
        unordered_map <int, int> m;
        int n = nums.size();

        // sorting bcoz we want to find the smallest than the current.
        sort(v.begin(), v.end()); // O(nlogn)

        // putting the values in map corresponding to their indices.
        // indicies will tell us how many elements are smaller than this element.
        // duplicates will also be handled bcoz map only keeps unique keys.
        for(int i = n-1; i>=0; i--) // O(n)
            m[v[i]] = i;

        for(int i=0; i<n; i++) // O(n)
            nums[i] = m[nums[i]];

        return nums;
    }
};