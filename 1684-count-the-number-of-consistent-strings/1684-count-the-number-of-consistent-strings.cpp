class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedBits = 0;

        for (int i = 0; i < allowed.length(); i++) {
            allowedBits |= 1 << (allowed[i] - 'a');
        }

        int consistentCount = 0;

        for (string& word : words) {
            bool isConsistent = true;

            for (int i = 0; i < word.length(); i++) {
                int bit = (allowedBits >> (word[i] - 'a')) & 1;

                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};