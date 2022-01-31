// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    vector<int> findUniquePair(int arr[], int n) {
    	// Complete the function and return the sorted vector.
		// In this function, the intuition is that if we XOR all the elements of the array, then XOR should be greater than equal to 1. One number will have the rightmost set bit at the same position as that of the XOR we just have calculated. But one number would definitely won't have the rightmost set bit at the same position at that of the XOR.
		
        int first = 0, second = 0, Xor = arr[0];
        vector <int> v;
		for(int i=1; i<n; i++)
			Xor ^= arr[i]; // getting the XOR of all elements which should be greater than 1 if two unique elements are present.

		int setBit = Xor & ~(Xor-1); // this operation is used to get the first set bit from the right and making all other bits as 0.

		for(int i=0; i<n; i++) {
			if(arr[i] & setBit) // ANDing the setBit with array elements will give us those elements whose has 1 at the same position as that of setBit
				first ^= arr[i]; // this operation will get us the unique element in this set
			else 
				second ^= arr[i]; // this operation will give us the unique element in the other set i.e. set of those numbers who does not have 1 at the same position as that of the setBit
		}

		// since vector should be sorted and only two elements are there in the vector
		v.push_back(min(first, second));
		v.push_back(max(first, second));
        return v;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n; 
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    vector<int> v;
	    Solution ob;
	    v = ob.findUniquePair(a, n);
	    cout<<v[0]<<" "<<v[1]<<endl;
	}
	return 0;
}
  // } Driver Code Ends