class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

        for (int i = n - 1; i >= 0; --i) {
            if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex]) {
                maxDigitIndex = i;
            } else if (numStr[i] < numStr[maxDigitIndex]) {
                swapIdx1 = i;
                swapIdx2 = maxDigitIndex;
            }
        }

        if (swapIdx1 != -1 && swapIdx2 != -1) {
            swap(numStr[swapIdx1], numStr[swapIdx2]);
        }

        return stoi(numStr);
    }
};