class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;

        for (auto a: A)
            res += count[a]++;

        return res;
    }
};