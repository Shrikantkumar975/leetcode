class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;

        q.push({0, 0});
        grid[0][0] = 1;

        vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};
        int count = 0;

        while (!q.empty()) {

            int siz = q.size();
            count++;
            while (siz--) {
                auto [x, y] = q.front();
                q.pop();
                if(x==n-1 && y==n-1) return count;

                for (int i = 0; i < 8; i++) {
                    int x1 = x + dx[i];
                    int y1 = y + dy[i];

                    if (x1 < n && x1 >= 0 && y1 < n && y1 >= 0 &&
                        grid[x1][y1] == 0) {
                        q.push({x1, y1});
                        grid[x1][y1] = 1;
                    }
                }
            }
        }

        return -1;
    }
};