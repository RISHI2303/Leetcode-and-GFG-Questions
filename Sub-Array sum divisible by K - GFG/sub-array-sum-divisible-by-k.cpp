// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K) {
	    // Your code goes here
	    unordered_map<long long, long long> m;
        m.insert({0, 1});
    
        long long sum = 0, rem = 0, ans = 0;
    
        for (long long i = 0; i < N; i++) {
            sum += arr[i];
            rem = sum % K;
            if(rem < 0)
                rem += K;
    
            if(m.find(rem) != m.end())
                ans += m[rem];
    
            m[rem]++;
        }
    
        return ans;
	}



};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends