class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> giftsHeap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int maxElement = giftsHeap.top();
            giftsHeap.pop();

            giftsHeap.push(sqrt(maxElement));
        }

        long long numberOfRemainingGifts = 0;
        while (!giftsHeap.empty()) {
            numberOfRemainingGifts += giftsHeap.top();
            giftsHeap.pop();
        }
        return numberOfRemainingGifts;
    }
};