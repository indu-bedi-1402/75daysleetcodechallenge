class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        for(auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(heights, nr, nc, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific borders
        for(int i = 0; i < m; i++)
            dfs(heights, i, 0, pacific);

        for(int j = 0; j < n; j++)
            dfs(heights, 0, j, pacific);

        // Atlantic borders
        for(int i = 0; i < m; i++)
            dfs(heights, i, n - 1, atlantic);

        for(int j = 0; j < n; j++)
            dfs(heights, m - 1, j, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};