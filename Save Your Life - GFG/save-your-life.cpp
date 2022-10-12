//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        string maxSum(string w,char x[], int b[],int n){
            
            unordered_map<char,int> mp;
            
            for(int i=0;i<n;i++){
                mp[x[i]] = b[i];
            }
            
            //kadane's algorithm
            int sum = INT_MIN;
            int currSum = 0;
            int start = 0;
            int end = 0;
            
            int s = 0;
            
            for(int i=0;i<w.size();i++){
                if(mp.count(w[i])){
                    currSum += mp[w[i]];
                }
                else{
                    currSum += w[i];
                }
                
                if(sum < currSum){
                    sum = currSum;
                    //extra step
                    start = s;
                    end = i;
                }
                
                if(currSum < 0){
                    currSum =0;
                    //extra step
                    s = i+1;
                }
            }
            
            return w.substr(start,end-start+1);
        }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends