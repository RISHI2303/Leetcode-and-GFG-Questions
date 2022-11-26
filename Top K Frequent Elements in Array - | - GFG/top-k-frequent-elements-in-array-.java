//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(s[i + 1]);
            }
            int k = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            int[] ans = obj.topK(nums, k);
            for (int i = 0; i < ans.length; i++) System.out.print(ans[i] + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    public int[] topK(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int val: nums)
        map.put(val, map.getOrDefault(val, 0)+1);
        
        PriorityQueue<Integer> pQueue= new PriorityQueue<>((a,b)->{
         
           if(map.get(a)==map.get(b))
               return a-b;
           return map.get(a) - map.get(b);
           });
           
        for(int n: map.keySet()) {
            pQueue.add(n);
            if(pQueue.size()>k)
            pQueue.poll();
        }
        
        int [] ans = new int[k];
        
        for(int i = k - 1; i >= 0;i--) {
            ans[i] = pQueue.poll();
        }
        return ans;
    }
}

// class MyComp implements Comparator<Map.Entry<Integer, Integer>> {

//     @Override
//     public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
//         if (Objects.equals(o1.getValue(), o2.getValue()))
//             return o1.getKey() - o2.getKey();
//         else
//             return o2.getValue() - o1.getValue();
//     }
// }