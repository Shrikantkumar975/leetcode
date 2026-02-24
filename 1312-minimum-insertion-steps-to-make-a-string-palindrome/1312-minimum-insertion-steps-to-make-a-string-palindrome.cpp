class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n = x.size();
        int m = y.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]) dp[i][j] =1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int minInsertions(string s) {
        int i=0;
        int j=s.size()-1;

        int count=0;

        string r=s;
        reverse(r.begin(),r.end());

        int common = longestCommonSubsequence(s,r);

        return s.size()-common;
    }
};