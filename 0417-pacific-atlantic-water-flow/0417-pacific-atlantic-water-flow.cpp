class Solution {
public:

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& heights, int n, int m)
    {
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true;

            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && heights[r][c] <= heights[nr][nc] && !vis[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m));
        vector<vector<bool>> atl(n, vector<bool>(m));
        queue<pair<int,int>>q;

        for(int i=n-1;i>=0;i--) q.push({i, 0});
        for(int i=m-1;i>=0;i--) q.push({0, i});

        bfs(q, pac, heights, n, m);

        for(int i=n-1;i>=0;i--) q.push({i, m-1});
        for(int i=m-1;i>=0;i--) q.push({n-1, i});

        bfs(q, atl, heights, n, m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};