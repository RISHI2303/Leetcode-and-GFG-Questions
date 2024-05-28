class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        
        int maxLen = 0;
        int start = 0;
        int currCost = 0;
        
        for (int i = 0; i < N; i++) {
            currCost += abs(s[i] - t[i]);
            
            while (currCost > maxCost) {
                currCost -= abs(s[start] - t[start]);
                start++;
            }
            
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};