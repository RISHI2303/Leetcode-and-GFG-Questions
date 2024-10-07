class Solution {
public:
    int minLength(string s) {
        int writePtr = 0;
        vector<char> charArray(s.begin(), s.end());

        for (int readPtr = 0; readPtr < s.length(); readPtr++) {
            charArray[writePtr] = charArray[readPtr];

            if (writePtr > 0 &&
                (charArray[writePtr - 1] == 'A' ||
                 charArray[writePtr - 1] == 'C') &&
                charArray[writePtr] == charArray[writePtr - 1] + 1) {
                writePtr--;
            } else {
                writePtr++;  
            }
        }

        return writePtr;
    }
};