class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream sentenceStream(sentence);
        string currentWord;

        int wordPosition = 1;

        while (sentenceStream >> currentWord) {
            if (currentWord.length() >= searchWord.length() &&
                currentWord.compare(0, searchWord.length(), searchWord) == 0) {
                return wordPosition;
            }
            wordPosition++;
        }
        return -1;
    }
};