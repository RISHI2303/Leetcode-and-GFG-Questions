class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0)
            return 0;
        unordered_set<int> s(num.begin(), num.end());
        int res = 1;
        for (int n : num) {
            if (s.find(n) == s.end())
                continue;
            s.erase(n);
            int prev = n - 1, next = n + 1;
            while (s.find(prev) != s.end())
                s.erase(prev--);
            while (s.find(next) != s.end())
                s.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};