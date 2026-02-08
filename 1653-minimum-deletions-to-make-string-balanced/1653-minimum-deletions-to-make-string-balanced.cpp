class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int min_deletions = 0;
        int b_count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};