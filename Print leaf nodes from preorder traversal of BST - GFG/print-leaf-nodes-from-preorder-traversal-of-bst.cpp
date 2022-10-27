//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int> v;
        stack<int> s;
        for(int i=0; i<N; i++){
            int count=0;
            int temp=0;
            while(!s.empty() && s.top()<arr[i]){
                if(temp==0)
                     temp=s.top();
                s.pop();
                count++;
            }
            if(count>=2){  
                v.push_back(temp);
            }
            s.push(arr[i]);
        }
        v.push_back(s.top());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends