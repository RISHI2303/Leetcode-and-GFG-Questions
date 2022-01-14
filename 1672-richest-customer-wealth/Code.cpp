class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int maxSum = INT_MIN, sum = 0;
      int n = accounts.size();

      for(auto i: accounts) {
          sum = 0;
          for(auto j: i) {
              sum += j;
          }

          maxSum = max(maxSum, sum);
      }

        return maxSum;
    }
};
