class Solution {
public:
    vector<int> distributeCandies(int N, int K) {
        vector <int> v(K, 0);
        int candies = 1, idx = 0;

        while(N) {
            v[idx++] += candies;
            N -= candies;
            candies++;

            if(idx == K)
                idx = 0;

            if(candies > N)
                candies = N;
        }

        return v;
    }
};