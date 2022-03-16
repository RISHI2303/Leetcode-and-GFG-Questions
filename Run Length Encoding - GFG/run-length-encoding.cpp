// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src) {
    // Write your code here
    int i = 0, j = 0;
    string ans = "";

    while(j < src.length()) {
        j++;

        if(src[i] != src[j]) {
            ans += src[i];
            ans += (to_string(j - i));
            i = j;
        }
    }

    return ans;
}   
 
