class Solution {
public:
    vector<int> runningSum(vector<int>& v) {
        vector <int> v1;
        int n = v.size();
        v1.push_back(v[0]);
        
        int sum = v[0];
        
        for(int i=1; i<n; i++) {
            sum += v[i];
            v1.push_back(sum);
        }
        
        return v1;
    }
};