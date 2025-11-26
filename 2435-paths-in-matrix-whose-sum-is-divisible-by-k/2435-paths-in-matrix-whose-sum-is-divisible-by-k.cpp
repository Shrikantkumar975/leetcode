class Solution {
public:
    int n, m, K;
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int sum_mod) {
        if (i >= n || j >= m) return 0;

        sum_mod = (sum_mod + grid[i][j]) % K;

        // reached destination
        if (i == n-1 && j == m-1) {
            return (sum_mod == 0);
        }

        // memoized answer already exists
        if (dp[i][j][sum_mod] != -1)
            return dp[i][j][sum_mod];

        long long right = solve(grid, i, j+1, sum_mod);
        long long down  = solve(grid, i+1, j, sum_mod);

        return dp[i][j][sum_mod] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        dp.assign(n, vector<vector<int>>(m, vector<int>(K, -1)));

        return solve(grid, 0, 0, 0);
    }
};
