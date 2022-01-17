class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map <int, char> m;
        int n = indices.size();

        for(int i=0; i<n; i++)
            m.insert({indices[i], s[i]});

        s.clear();

        for(auto i: m)
            s += i.second;

        return s;
    }
};