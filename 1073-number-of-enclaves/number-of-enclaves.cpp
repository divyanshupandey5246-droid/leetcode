class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visi(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        // Put all boundary land cells into queue
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !visi[i][0]) {
                q.push({i, 0});
                visi[i][0] = true;
            }

            if(grid[i][m-1] == 1 && !visi[i][m-1]) {
                q.push({i, m-1});
                visi[i][m-1] = true;
            }
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !visi[0][j]) {
                q.push({0, j});
                visi[0][j] = true;
            }

            if(grid[n-1][j] == 1 && !visi[n-1][j]) {
                q.push({n-1, j});
                visi[n-1][j] = true;
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // BFS
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                   grid[nx][ny] == 1 && !visi[nx][ny]) {

                    visi[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // Count land which cannot reach boundary
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visi[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};