class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> mySet;
        int i = 0, j = 0, n = s.length(), ans = 0;
        
        while(i < n && j < n) {
            if(mySet.find(s[j]) == mySet.end()) {
                mySet.insert(s[j]);
                j++;
                ans = max(ans, j - i);
            }
            
            else {
                mySet.erase(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};