class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> characterSet;
        int res = 0;

        for (char c : s) {
            if (characterSet.find(c) != characterSet.end()) {
                characterSet.erase(c);
                res += 2;
            } else {
                characterSet.insert(c);
            }
        }
        if (!characterSet.empty()) {
            res++;
        }

        return res;
    }
};