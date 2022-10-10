//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
class Solution {
  public:
    vector<int>sz,par;
    int find(int v){
        if(par[v]==v)return v;
        return par[v]=find(par[v]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]<sz[b])swap(a,b);
            sz[a]+=sz[b];
            par[b]=a;
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        sz.resize(n*m+1,1);
        par.resize(n*m+1);
        for(int i=0;i<n*m;i++)par[i]=i;
        
        vector<int>ans;
        vector<vector<int>>a(n,vector<int>(m,0));
        
        int u,v,cnt=0;
        for(auto it:op){
            int x=it[0],y=it[1];
            u=m*x+y;
            for(int k=0;k<4;k++){
               int newx=x+dx[k];
               int newy=y+dy[k];
               if(newx>=0&&newy>=0&&newx<n&&newy<m&&a[newx][newy]==1){
               v=m*newx+newy;
               Union(u,v);
               }
            }
            a[x][y]=1;
            cnt=0;
            for(int i=0;i<n*m;i++)if(find(i)==i&&a[i/m][i%m]==1)cnt++;
            ans.push_back(cnt);
        }
   
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends