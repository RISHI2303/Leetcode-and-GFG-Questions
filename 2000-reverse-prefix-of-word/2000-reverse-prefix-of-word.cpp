class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;

        for (int right = 0; right < word.length(); right++) {
            // We found ch - reverse characters up to ch by swapping
            if (word[right] == ch) {
                while (left <= right) {
                    swap(word[right], word[left]);
                    left++;
                    right--;
                }
                return word;
            }
        }
        return word;
    }
};