// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    // return 1 for YES and 0 for NO.
    bool areRotations(string str1, string str2) {
        // Write your code here
    
        if(str1.length() != str2.length())
            return false;
    
        str1.append(str1);
    
        if(str1.find(str2) == -1)
            return false;
    
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
  // } Driver Code Ends