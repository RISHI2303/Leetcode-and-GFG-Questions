class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> heap;
        heap.push(a);
        heap.push(b);
        heap.push(c);
        int cnt = 0;
        while (heap.size() > 1) {
            auto u = heap.top();
            heap.pop();
            auto v = heap.top();
            heap.pop();
            if (--u > 0)
                heap.push(u);
            if (--v > 0)
                heap.push(v);
            cnt++;
        }
        return cnt;
    }
};