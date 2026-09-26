class Solution {
public:
 bool bfs(vector<vector<int>>& grid, int r, int c) {
      int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r, c});
        grid[r][c] = 1;

        bool closed = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // If island touches boundary, it is not closed
            if (x == 0 || x == n-1 || y == 0 || y == m-1) {
                closed = false;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    grid[nx][ny] == 0) {

                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
     int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {
                    if (bfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;    
    }
};