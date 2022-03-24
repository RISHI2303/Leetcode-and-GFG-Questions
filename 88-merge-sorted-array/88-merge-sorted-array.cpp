class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
        int i = 0, j = 0, k = 0;
        vector <int> v;
    
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                v.push_back(nums1[i++]);
            else if (nums2[j] < nums1[i])
                v.push_back(nums2[j++]);
            else
            {
                v.push_back(nums1[i++]);
                v.push_back(nums2[j++]);
            }
        }
    
        while (i < m)
            v.push_back(nums1[i++]);
    
        while (j < n)
            v.push_back(nums2[j++]);
    
        nums1.clear();
    
        nums1.assign(v.begin(), v.end());
    }
};