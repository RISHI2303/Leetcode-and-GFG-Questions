class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;
        while (xorResult) {
            xorResult &= (xorResult - 1); 
            count++;
        }
        return count;
    }
};