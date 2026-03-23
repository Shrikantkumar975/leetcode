class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long,long long>>> v(m, vector<pair<long long,long long>>(n));

        v[m-1][n-1] = {grid[m-1][n-1], grid[m-1][n-1]};

        // Last column
        for(int i = m-2; i >= 0; i--){
            long long val = grid[i][n-1];
            v[i][n-1].first = val * v[i+1][n-1].first;
            v[i][n-1].second = val * v[i+1][n-1].second;
        }

        // Last row
        for(int j = n-2; j >= 0; j--){
            long long val = grid[m-1][j];
            v[m-1][j].first = val * v[m-1][j+1].first;
            v[m-1][j].second = val * v[m-1][j+1].second;
        }

        // DP
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                long long val = grid[i][j];

                long long a = val * v[i+1][j].first;
                long long b = val * v[i+1][j].second;
                long long c = val * v[i][j+1].first;
                long long d = val * v[i][j+1].second;

                long long maxVal = max({a, b, c, d});
                long long minVal = min({a, b, c, d});

                v[i][j] = {maxVal, minVal};  // ✅ critical
            }
        }

        long long res = v[0][0].first;
        if(res < 0) return -1;

        return res % 1000000007;
    }
};