//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k) {
    stack<char> st;
    string ans = "";
    for(auto ch : num){
        while(!st.empty() and st.top() > ch and k-->0) st.pop();
        st.push(ch);
    }
    while(!st.empty() and k-->0) st.pop();
    while(!st.empty()) ans += st.top(), st.pop();
    while(ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0":ans;
}