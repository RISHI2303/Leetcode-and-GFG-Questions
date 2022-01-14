class Solution {
public:
    vector<int> buildArray(vector<int>& v) {
        vector<int> v1;
        int n = v.size();
        
        for(int i=0; i<n; i++) {
            v1.push_back(v[v[i]]);
        }
        
        return v1;
    }
};