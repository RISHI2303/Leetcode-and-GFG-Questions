class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        unordered_map <int, int> m;
        unordered_set <int> s;
    
        for(int i: v) {
            m[i]++;
        }
    
        for(auto i: m) {
            if(s.find(i.second) == s.end())
                s.insert(i.second);
            else
                return false;
        }
    
        return true;
    }
};