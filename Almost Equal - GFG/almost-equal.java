//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String s1 = br.readLine().trim();
            String s2 = br.readLine().trim();
            Solution obj = new Solution();
            System.out.println(obj.countChars(s1, s2));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public int countChars(String s1, String s2) {
        // Code here
        int[] a = new int[26];
        int[] b = new int[26];
        int ans = 0;

        for (int i = 0; i < s1.length(); i++)
            a[s1.charAt(i) - 'a']++;

        for (int i = 0; i < s2.length(); i++)
            b[s2.charAt(i) - 'a']++;

        for (int i = 0; i < 26; i++)
            ans += Math.abs(a[i] - b[i]);

        return ans;
    }
}