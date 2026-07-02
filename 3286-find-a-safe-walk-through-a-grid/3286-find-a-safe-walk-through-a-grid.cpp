class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        queue<tuple<int, int, int>> q;

        vector<vector<pair<int, int>>> vis(n,
                                           vector<pair<int, int>>(m, {0, 0}));

        if (grid[0][0] >= health) {
            return false;
        }

        q.push({0, 0, grid[0][0]});
        vis[0][0] = {1, grid[0][0]};

        while (!q.empty()) {
            auto [i, j, h] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    h + grid[ni][nj] < health) {
                    if (vis[ni][nj].first == 0 ||
                        (vis[ni][nj].first == 1 &&
                         vis[ni][nj].second > h + grid[ni][nj])) {
                        q.push({ni, nj, h + grid[ni][nj]});
                        vis[ni][nj] = {1, h + grid[ni][nj]};
                    }
                }
            }
        }

        return vis[n - 1][m - 1].first == 1;
    }
};