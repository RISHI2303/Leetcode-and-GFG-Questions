class Solution {
public:
    int finalValueAfterOperations(vector<string>& v) {
        int n = v.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(v[i].at(0) == '+' || v[i].at(1) == '+')
                ans  += 1;
            else
                ans -= 1;
        }

        return ans;
    }
};