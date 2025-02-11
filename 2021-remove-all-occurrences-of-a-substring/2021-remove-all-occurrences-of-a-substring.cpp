class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<int> kmpLPS = computeLongestPrefixSuffix(part);

        stack<char> charStack;

        vector<int> patternIndexes(s.length() + 1, 0);

        for (int strIndex = 0, patternIndex = 0; strIndex < s.length();
             strIndex++) {
            char currentChar = s[strIndex];
            charStack.push(currentChar);

            if (currentChar == part[patternIndex]) {
                patternIndexes[charStack.size()] = ++patternIndex;

                if (patternIndex == part.length()) {
                    int remainingLength = part.length();
                    while (remainingLength != 0) {
                        charStack.pop();
                        remainingLength--;
                    }

                    patternIndex = charStack.empty()
                                       ? 0
                                       : patternIndexes[charStack.size()];
                }
            } else {
                if (patternIndex != 0) {
                    strIndex--;
                    patternIndex = kmpLPS[patternIndex - 1];
                    charStack.pop();
                } else {
                    patternIndexes[charStack.size()] = 0;
                }
            }
        }

        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }

private:
    vector<int> computeLongestPrefixSuffix(string pattern) {
        vector<int> lps(pattern.length(), 0);

        for (int current = 1, prefixLength = 0; current < pattern.length();) {
            if (pattern[current] == pattern[prefixLength]) {
                lps[current] = ++prefixLength;
                current++;
            }
            else if (prefixLength != 0) {
                prefixLength = lps[prefixLength - 1];
            }
            else {
                lps[current] = 0;
                current++;
            }
        }

        return lps;
    }
};