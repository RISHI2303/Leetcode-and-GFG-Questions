class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionSizes;
        int lastOccurrence[26] = {0}, firstOccurrence[26] = {0};
        int partitionStart = 0, partitionEnd = 0;

        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!firstOccurrence[s[i] - 'a']) {
                firstOccurrence[s[i] - 'a'] = i;
            }

            if (partitionEnd < firstOccurrence[s[i] - 'a']) {
                partitionSizes.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i;
                partitionEnd = i;
            }

            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
        }

        if (partitionEnd - partitionStart + 1 > 0) {
            partitionSizes.push_back(partitionEnd - partitionStart + 1);
        }

        return partitionSizes;
    }
};