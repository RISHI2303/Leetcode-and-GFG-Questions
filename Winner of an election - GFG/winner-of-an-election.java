//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            String arr[] = new String[n];
            
            for(int i = 0; i < n; i++)
                arr[i] = sc.next();
            
            Solution obj = new Solution();    
            String result[] = obj.winner(arr, n);
            System.out.println(result[0] + " " + result[1]);
            
           
        }
        
    }
}

// } Driver Code Ends


//User function Template for Java


class Solution
{
    //Function to return the name of candidate that received maximum votes.
    public static String[] winner(String[] arr, int n) {
        // add your code
        TreeMap<String, Integer> m = new TreeMap<>();
        for (String x : arr)
            m.put(x, m.getOrDefault(x, 0) + 1);

        int max = Integer.MIN_VALUE;
        String[] ans = new String[2];

        for (Map.Entry<String, Integer> x : m.entrySet()) {
            if (x.getValue() > max) {
                max = x.getValue();
                ans[0] = x.getKey();
                ans[1] = x.getValue().toString();
            }
        }

        return ans;
    }
}

