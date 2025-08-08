class Solution {
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0; // Optimization for large n

        vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};

        // dp[i][j] = probability that soup A empties first
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

        // Base cases
        dp[0][0] = 0.5; // both empty
        for (int i = 1; i <= n; i++) dp[0][i] = 1.0; // A empty, B not
        for (int i = 1; i <= n; i++) dp[i][0] = 0.0; // B empty, A not

        // Fill table from small to large
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                double probability = 0.0;
                for (auto &p : serves) {
                    int na = max(0, a - p.first);
                    int nb = max(0, b - p.second);
                    probability += 0.25 * dp[na][nb];
                }
                dp[a][b] = probability;
            }
        }

        return dp[n][n];
    }
};
