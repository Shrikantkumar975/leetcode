class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].length();

        queue<vector<int>> q;

        int total = 0;
        int sx, sy;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if(classroom[i][j] == 'L') {
                    id[i][j] = total++;
                }
            }
        }

        if(total == 0)
            return 0;

        int fullMask = (1 << total) - 1;

        vector<vector<vector<int>>> maxEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << total, -1)
            )
        );

        q.push({sx, sy, 0, energy, 0});
        maxEnergy[sx][sy][0] = energy;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        while(!q.empty()) {

            auto currState = q.front();
            q.pop();

            int x = currState[0];
            int y = currState[1];
            int mask = currState[2];
            int e = currState[3];
            int steps = currState[4];

            if(mask == fullMask)
                return steps;

            if(e == 0)
                continue;

            for(int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 ||
                   nx >= n || ny >= m)
                    continue;

                if(classroom[nx][ny] == 'X')
                    continue;

                int newEnergy = e - 1;
                int newMask = mask;

                if(classroom[nx][ny] == 'L') {
                    int bit = id[nx][ny];
                    newMask |= (1 << bit);
                }

                if(classroom[nx][ny] == 'R') {
                    newEnergy = energy;
                }

                if(maxEnergy[nx][ny][newMask] >= newEnergy)
                    continue;

                maxEnergy[nx][ny][newMask] = newEnergy;

                q.push({
                    nx,
                    ny,
                    newMask,
                    newEnergy,
                    steps + 1
                });
            }
        }

        return -1;
    }
};