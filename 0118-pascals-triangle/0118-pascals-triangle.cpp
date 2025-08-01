class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;

        dp.push_back({1});
        int i = 0;
        n--;
        while (n--) {
            vector<int> v;
            for (int j = 0; j < dp[i].size() + 1; j++) {
                if (j == 0 || j == dp[i].size()) {
                    v.push_back(1);
                } else {
                    v.push_back(dp[i][j] + dp[i][j - 1]);
                }
            }
            dp.push_back(v);
            i++;
        }

        return dp;
    }
};