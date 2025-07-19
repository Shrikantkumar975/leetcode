class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int a = entrance[0];
        int b = entrance[1];

        int rows = maze.size();
        int columns = maze[0].size();

        if (maze[a][b] == '+') return -1;

        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};

        queue<pair<int, int>> q;
        q.push({a, b});
        maze[a][b] = '+';  // mark as visited

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Check boundaries
                    if (nx >= 0 && ny >= 0 && nx < rows && ny < columns && maze[nx][ny] == '.') {
                        // Check if it's an exit and not the entrance
                        if (nx == 0 || ny == 0 || nx == rows - 1 || ny == columns - 1) {
                            return steps;
                        }
                        maze[nx][ny] = '+'; // mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1; // no exit found
    }
};
