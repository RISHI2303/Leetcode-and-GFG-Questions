class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

        string modifiedString = preprocessString(s);
        int n = modifiedString.size();
        vector<int> palindromeRadiusArray(n, 0);
        int center = 0, rightBoundary = 0;
        int maxPalindromeLength = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirrorIndex = 2 * center - i;

            if (rightBoundary > i) {
                palindromeRadiusArray[i] =
                    min(rightBoundary - i, palindromeRadiusArray[mirrorIndex]);
            }

            while (modifiedString[i + 1 + palindromeRadiusArray[i]] ==
                   modifiedString[i - 1 - palindromeRadiusArray[i]]) {
                ++palindromeRadiusArray[i];
            }

            if (i + palindromeRadiusArray[i] > rightBoundary) {
                center = i;
                rightBoundary = i + palindromeRadiusArray[i];
            }

            if (i - palindromeRadiusArray[i] == 1) {
                maxPalindromeLength =
                    max(maxPalindromeLength, palindromeRadiusArray[i]);
            }
        }

        string suffix = s.substr(maxPalindromeLength);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }

private:
    string preprocessString(const string& s) {
        string result = "^";
        for (char c : s) {
            result += "#" + string(1, c);
        }
        result += "#$";
        return result;
    }
};