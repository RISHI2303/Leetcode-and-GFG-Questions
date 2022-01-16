class Solution {
public:
    int numJewelsInStones(string &jewels, string &stones) {
        int count = 0;
        unordered_map<char, int> m;

        for(auto i: jewels)
            m[i]++;

        for(auto i: stones){
            auto it = m.find(i);
            if(it != m.end())
                count += it->second;
        }

        return count;
    }
};