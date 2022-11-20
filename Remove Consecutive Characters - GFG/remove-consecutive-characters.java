//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String S = read.readLine().trim();
            
            Solution ob = new Solution();
            String ans = ob.removeConsecutiveCharacter(S);
            
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    public String removeConsecutiveCharacter(String S) {
        ArrayDeque<Character> st = new ArrayDeque<>();
        st.push(S.charAt(S.length() - 1));
        for (int i = S.length() - 2; i >= 0; i--) {
            if (S.charAt(i) != st.peek())
                st.push(S.charAt(i));
        }

        S = "";

        while (!st.isEmpty())
            S += st.pop();

        return S;
    }
}