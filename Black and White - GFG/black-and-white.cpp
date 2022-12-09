//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m) {
    // write code here
    long long mod=1000000007;
    long long total=((n*m)%mod*(n*m-1)%mod)%mod;
    
    if(n>=1 && m>=2)
        total-=4*(n-1)*(m-2);
        
    if(n>=2 && m>=1)
        total-=4*(n-2)*(m-1);
    
    return total;
}