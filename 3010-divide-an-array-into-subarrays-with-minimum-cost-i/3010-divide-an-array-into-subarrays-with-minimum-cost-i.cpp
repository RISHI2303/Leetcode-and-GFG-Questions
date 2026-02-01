class Solution {
public:
    int minimumCost(vector<int>& A) {
        for (int i = 1; i <= 2; i++) {
            int m = i;
            for (int j = i + 1; j < A.size(); j++)
                if (A[j] < A[m])
                    m = j;
            swap(A[i], A[m]);
        }
        return A[0] + A[1] + A[2];
    }
};