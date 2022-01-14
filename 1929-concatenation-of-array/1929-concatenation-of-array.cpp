class Solution {
public:
    vector<int> getConcatenation(vector<int>& v) {
        int n = v.size();
        vector <int> v1;

        for(int i=0; i<2*n; i++) {
            if(i >= n)
                v1.push_back(v[i-n]);
            else
                v1.push_back(v[i]);
        }

        return v1;
    }
};