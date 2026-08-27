class Solution {

    public String lexGreaterPermutation(String s, String target) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
            cnt[target.charAt(i) - 'a']--;
        }

        char[] t = target.toCharArray();
        for (int i = s.length() - 1; i >= 0; i--) {
            int b = t[i] - 'a';
            cnt[b]++;
            if (Arrays.stream(cnt).min().getAsInt() < 0) {
                continue;
            }
            for (int j = b + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    t[i] = (char) ('a' + j);
                    return new String(t, 0, i + 1) + getMinString(cnt);
                }
            }
        }

        return "";
    }

    private String getMinString(int[] cnt) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            res.append(String.valueOf((char) ('a' + i)).repeat(cnt[i]));
        }
        return res.toString();
    }
}