class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> temp(words.size());
        int result = 0;
        for (int i=0; i<words.size(); ++i) {
            for (char c : words[i])
                temp[i] |= 1 << (c - 'a');
            for (int j=0; j<i; ++j)
                if (!(temp[i] & temp[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }
        return result;
    }
};