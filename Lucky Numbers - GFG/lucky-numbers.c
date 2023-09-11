//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


// } Driver Code Ends
//User function Template for C

// Complete the function
// n: Input n
// Return true if the given number is a lucky number else return False

bool myFun(int n, int x){
    if(n%x == 0)
        return false;
    if(x > n)
        return true;
    return myFun(n-(n/x), x+1);
}
bool isLucky(int n) {
    return myFun(n, 2);
}

//{ Driver Code Starts.

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        //calling isLucky() function
        if(isLucky(n))
            printf("1\n");//printing "1" if isLucky() returns true
        else
            printf("0\n");//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends