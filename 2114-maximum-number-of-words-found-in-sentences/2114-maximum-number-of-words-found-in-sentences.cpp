class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
    int maxWordCount = INT_MIN, wordCount = 0;
    int n = sentences.size();

    for(int i=0; i<n; i++) {
        int len = sentences[i].length();
        wordCount = 1;
        for(int j=0; j<len; j++) {
            if(sentences[i].at(j) == ' ') {
                wordCount++;
            }
        }

        maxWordCount = max(wordCount, maxWordCount);
    }

    return maxWordCount;
}
};