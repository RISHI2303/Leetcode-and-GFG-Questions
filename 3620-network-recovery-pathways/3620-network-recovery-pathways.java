class Solution {

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int n = online.length;
        List<int[]>[] g = new ArrayList[n];
        int[] deg = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }

        int l = Integer.MAX_VALUE,
            r = 0;
        for (int[] edge : edges) {
            int u = edge[0],
                v = edge[1],
                w = edge[2];
            if (!online[u] || !online[v]) {
                continue;
            }
            g[u].add(new int[] { v, w });
            deg[v]++;
            l = Math.min(l, w);
            r = Math.max(r, w);
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i < n; i++) {
            if (deg[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int[] edge : g[u]) {
                int v = edge[0];
                if (--deg[v] == 0 && v != 0) {
                    q.offer(v);
                }
            }
        }

        if (!check(l, k, g, deg, n)) {
            return -1;
        }

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, k, g, deg, n)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }

    private boolean check(int mid, long k, List<int[]>[] g, int[] deg, int n) {
        long[] dp = new long[n];
        Arrays.fill(dp, Long.MAX_VALUE / 2);
        int[] cdeg = deg.clone();
        dp[0] = 0;

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);

        while (!q.isEmpty()) {
            int u = q.poll();
            if (u == n - 1) {
                return dp[u] <= k;
            }

            for (int[] edge : g[u]) {
                int v = edge[0],
                    w = edge[1];
                if (w >= mid) {
                    dp[v] = Math.min(dp[v], dp[u] + w);
                }
                if (--cdeg[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return false;
    }
}