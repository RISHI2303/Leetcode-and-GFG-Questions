//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here
        int k;
        int ans = 0;
        for(int i=0; i<S.size(); ++i){
            if(S[i] == W[0]){
                k = 0 ;
                for(int j=i; j<S.size(); ++j){
                    if(S[j] == W[k]){
                        S[j] = '$';
                        k++;
                        if(k == W.size()){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends