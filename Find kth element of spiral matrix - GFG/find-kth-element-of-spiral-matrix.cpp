//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		string str = "right";
 	    vector<vector<bool>> vis;
 	    for(int i=0; i<n; i++){
 	        vector<bool> c(m, false);
 	        vis.push_back(c);
 	    }
 	    int i=0, j=0, val=a[0][0];
 		while(k--){
 		    vis[i][j] = true;
 		    val = a[i][j];
 		    if (str == "right" and (j+1<m) and vis[i][j+1]) str="down";
 		    else if (str == "down" and (i+1<n) and vis[i+1][j]) str="left";
 		    else if (str == "left" and j-1>=0 and vis[i][j-1]) str="up";
 		    else if (str == "up" and i-1>=0 and vis[i-1][j]) str="right";
 		    if (str == "right") j++;
 		    else if (str == "down") i++;
 		    else if (str == "left") j--;
 		    else i--;
 		    if (i==0 and j==m-1) str = "down";
 		    else if (i==n-1 and j==m-1) str = "left";
 		    else if (i==n-1 and j==0) str = "up";
 		    
 		}
 		return val;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends