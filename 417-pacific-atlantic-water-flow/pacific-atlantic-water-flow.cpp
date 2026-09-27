class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             int r, int c,
             vector<vector<bool>>& visited,
             vector<vector<bool>>& ocean) {

        int n = heights.size();
        int m = heights[0].size();

        visited[r][c] = true;
        ocean[r][c] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               !visited[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(heights, nr, nc, visited, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific DFS
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Top row + Left column
        for(int j = 0; j < m; j++) {
            if(!visited[0][j])
                dfs(heights, 0, j, visited, pacific);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][0])
                dfs(heights, i, 0, visited, pacific);
        }

        // Atlantic DFS
        visited.assign(n, vector<bool>(m, false));

        // Bottom row + Right column
        for(int j = 0; j < m; j++) {
            if(!visited[n-1][j])
                dfs(heights, n-1, j, visited, atlantic);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i][m-1])
                dfs(heights, i, m-1, visited, atlantic);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};