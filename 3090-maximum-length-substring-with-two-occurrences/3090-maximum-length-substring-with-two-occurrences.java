class Solution {
    public int maximumLengthSubstring(String s) {
        int[] charFreq = new int[26];
        
        int maxWindowLen = 0;
        
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currChar = s.charAt(right);
            
            charFreq[currChar - 'a']++;
            
            while (charFreq[currChar - 'a'] > 2) {
                charFreq[s.charAt(left) - 'a']--;
                left++;
            }
            
            int currentWindowLen = right - left + 1;
            maxWindowLen = Math.max(maxWindowLen, currentWindowLen);
        }
        
        return maxWindowLen;
    }
}