class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;

        // Push all initially rotten oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // No fresh oranges to rot

        int time = -1;

        while (!q.empty()) {
            int n = q.size();
            time++; // One level = one minute

            while (n--) {
                pair<int, int> v = q.front();
                q.pop();
                int i = v.first;
                int j = v.second;

                // check up
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                    fresh--;
                }
                // check down
                if (i + 1 < r && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                    fresh--;
                }
                // check left
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                    fresh--;
                }
                // check right
                if (j + 1 < c && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                    fresh--;
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }
};
