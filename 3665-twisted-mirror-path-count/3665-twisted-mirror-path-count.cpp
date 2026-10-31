class Solution {
public:
    const int MOD = 1e9 + 7;
    int total[500][500][2];
    int m,n;

    int solve(vector<vector<int>> &grid,int i, int j, int dir){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(total[i][j][dir] != -1){
            return total[i][j][dir];
        }

        total[i][j][dir]=0;

        if(grid[i][j]==1){
            if(dir == 1){
                total[i][j][dir] = (total[i][j][dir] + solve(grid,i+1,j,0)) % MOD;
            }else{
                total[i][j][dir] = (total[i][j][dir] + solve(grid,i,j+1,1)) % MOD;
            }
        }else{
            total[i][j][dir] = (solve(grid,i,j+1,1) + 1LL * solve(grid,i+1,j,0)) % MOD;
        }

        return total[i][j][dir];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();

        memset(total, -1, sizeof(total));

        return solve(grid,0,0,0);
    }
};