class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), [](vector<int>& X, vector<int>& Y){ 
            const int x0=X[0], x1=X[1], y0=Y[0], y1=Y[1]; 
            return (x0==y0)?x1<y1:x0>y0; 
        });
        int cnt=2, n=I.size();
        // two smallest chosen points so far
        int a=I[0][0], b=a+1;
        for (int i=1; i<n; i++) {
            const int L=I[i][0], R=I[i][1];
            if (b<=R) continue;
            bool NO=R<a;
            cnt+=1+NO;
            b=(NO)?L+1:a;
            a=L;
        }
        return cnt;
    }
};
