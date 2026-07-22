class Solution {

    public List<Integer> maxActiveSectionsAfterTrade(
        String s,
        int[][] queries
    ) {
        int n = s.length(),
            m = queries.length;
        int cnt1 = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') cnt1++;
        }
        // left[i]: represents the length of the continuous block ending at position i, which is the same as s[i]
        int[] left = new int[n];
        // right[i]: represents the length of the continuous block starting at position i with the same value as s[i]
        int[] right = new int[n];

        for (int i = 0; i < n; i++) {
            left[i] =
                i > 0 && s.charAt(i - 1) == s.charAt(i) ? left[i - 1] + 1 : 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            right[i] =
                i < n - 1 && s.charAt(i + 1) == s.charAt(i)
                    ? right[i + 1] + 1
                    : 1;
        }

        List<Integer> ans = new ArrayList<>(Collections.nCopies(m, -1));
        int block_size = (int) Math.sqrt(n);
        // query with length greater than block length
        List<int[]> longQueries = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int l = queries[i][0],
                r = queries[i][1];
            if (r - l + 1 > block_size) {
                longQueries.add(new int[] { l / block_size, l, r, i });
            } else {
                // queries shorter than block length, brute-force calculation
                ans.set(i, cnt1 + bruteForce(s, l, r));
            }
        }

        // sort by the ID of the block where the left endpoint is located as the first keyword, and by the right endpoint as the second keyword
        longQueries.sort((a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[2], b[2]);
        });

        Deque<Integer> subZeroBlocks = new ArrayDeque<>();
        int L = 0,
            R = 0,
            bestGain = 0;

        for (int i = 0; i < longQueries.size(); i++) {
            int[] q = longQueries.get(i);
            int bid = q[0],
                l = q[1],
                r = q[2],
                qid = q[3];

            if (i == 0 || bid > longQueries.get(i - 1)[0]) {
                // traverse to a new block, perform initialization operations
                L = (bid + 1) * block_size - 1; // L is initialized to the right endpoint of the block
                R = (bid + 1) * block_size; // R is initialized to the left endpoint of the next block
                subZeroBlocks.clear();
                bestGain = 0;
            }

            while (R <= r) {
                int sz = Math.min(r - R + 1, right[R]);
                if (s.charAt(R) == '0') {
                    if (!subZeroBlocks.isEmpty() && s.charAt(R - 1) == '0') {
                        subZeroBlocks.offerLast(subZeroBlocks.pollLast() + sz);
                    } else {
                        subZeroBlocks.offerLast(sz);
                    }
                    if (subZeroBlocks.size() >= 2) {
                        int last = subZeroBlocks.pollLast();
                        int secondLast = subZeroBlocks.peekLast();
                        subZeroBlocks.offerLast(last);
                        bestGain = Math.max(last + secondLast, bestGain);
                    }
                }
                R += sz;
            }

            // before moving the left endpoint L, backup the value of bestGain
            int tmp_bestGain = bestGain;
            // value of the first element of subZeroBlocks before moving the left endpoint
            int tmp_firstValue = subZeroBlocks.isEmpty()
                ? -1
                : subZeroBlocks.peekFirst();
            // the number of digits added from the left during the process of recording the movement of the left endpoint L
            int cnt = 0;

            while (L >= l) {
                int sz = Math.min(L - l + 1, left[L]);
                if (s.charAt(L) == '0') {
                    if (!subZeroBlocks.isEmpty() && s.charAt(L + 1) == '0') {
                        subZeroBlocks.offerFirst(
                            subZeroBlocks.pollFirst() + sz
                        );
                    } else {
                        subZeroBlocks.offerFirst(sz);
                        cnt++;
                    }
                    if (subZeroBlocks.size() >= 2) {
                        int first = subZeroBlocks.peekFirst();
                        subZeroBlocks.pollFirst();
                        int second = subZeroBlocks.peekFirst();
                        subZeroBlocks.offerFirst(first);
                        bestGain = Math.max(first + second, bestGain);
                    }
                }
                L -= sz;
            }

            // answering inquiries
            ans.set(qid, bestGain + cnt1);
            // restore left endpoint L
            L = (bid + 1) * block_size - 1;
            // restore bestGain
            bestGain = tmp_bestGain;
            // restore subZeroBlocks
            for (int j = 0; j < cnt; j++) {
                subZeroBlocks.pollFirst();
            }
            if (tmp_firstValue != -1) {
                subZeroBlocks.pollFirst();
                subZeroBlocks.offerFirst(tmp_firstValue);
            }
        }
        return ans;
    }

    private int bruteForce(String s, int l, int r) {
        int i = l;
        int best = 0;
        int prev = Integer.MIN_VALUE;

        while (i <= r) {
            int start = i;
            while (i <= r && s.charAt(i) == s.charAt(start)) {
                i++;
            }
            if (s.charAt(start) == '0') {
                int cur = i - start;
                if (prev != Integer.MIN_VALUE && prev + cur > best) {
                    best = prev + cur;
                }
                prev = cur;
            }
        }
        return best;
    }
}