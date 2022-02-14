class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = height[0];
        int rMax = height[n-1];
        int i = 1, j = n-2, ans = 0;
    
        while(i <= j) {
            lMax = max(lMax, height[i]);
            rMax = max(rMax, height[j]);
    
            if(lMax < rMax) {
                ans += (lMax - height[i]);
                i++;
            }
    
            else {
                ans += (rMax - height[j]);
                j--;
            }
        }
    
        return ans;
    }
};