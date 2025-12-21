class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int N = strs.size();
        if (N == 0) return 0;
        int W = strs[0].length();
        
        vector<bool> cuts(N - 1, false);
        int ans = 0;

        for (int j = 0; j < W; ++j) {
            bool shouldDelete = false;
            
            for (int i = 0; i < N - 1; ++i) {
                if (!cuts[i] && strs[i][j] > strs[i+1][j]) {
                    shouldDelete = true;
                    break;
                }
            }

            if (shouldDelete) {
                ans++;
            } else {
                for (int i = 0; i < N - 1; ++i) {
                    if (strs[i][j] < strs[i+1][j]) {
                        cuts[i] = true;
                    }
                }
            }
        }

        return ans;
    }
};