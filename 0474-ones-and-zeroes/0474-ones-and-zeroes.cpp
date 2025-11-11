class Solution {
public:
    pair<int,int> check(string& s,int m,int n){
        int zeros = 0, ones = 0;
        for(char ch: s){
            if(ch == '1') ones++;
            else zeros++;
        }
        return {zeros, ones};
    }

    int solve(vector<pair<int,int>>& count, int m, int n, int l, vector<vector<vector<int>>>& dp) {
        if(l == 0) return 0;  // base case

        if(dp[l][m][n] != -1) return dp[l][m][n];  // already computed

        int take = 0;
        if(count[l-1].first <= m && count[l-1].second <= n) {
            take = 1 + solve(count, m - count[l-1].first, n - count[l-1].second, l - 1, dp);
        }

        int skip = solve(count, m, n, l - 1, dp);

        return dp[l][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        vector<pair<int,int>> count;

        for(string &s: strs){
            count.push_back(check(s, m, n));
        }

        // dp[l][m][n] means: max number of strings using first l strings with m zeros and n ones
        vector<vector<vector<int>>> dp(L + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(count, m, n, L, dp);
    }
};
