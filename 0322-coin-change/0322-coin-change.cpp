class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n= coins.size();
        const int INF = 1e9 + 7;

        vector<vector<int>> dp(n+1,vector<int>(target+1,INF));

        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target] == INF?-1:dp[n][target];
    }
};