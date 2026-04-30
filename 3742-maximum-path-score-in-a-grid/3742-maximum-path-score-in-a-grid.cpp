class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

        dp[0][0][0]=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s = grid[i][j];
                int cost = (grid[i][j]==1 || grid[i][j]==2)? 1:0;

                for(int c=cost;c<=k;c++){
                    int maxi = -1;
                    if(i>0 && dp[i-1][j][c-cost]!=-1)
                        maxi = max(maxi,dp[i-1][j][c-cost]);
                    if(j>0 && dp[i][j-1][c-cost]!=-1)
                        maxi = max(maxi,dp[i][j-1][c-cost]);

                    if(maxi!=-1){
                        dp[i][j][c] = maxi + s;
                    }
                }
            }
        }
        int ans = -1;
        for(int i=0;i<=k;i++){
            ans = max(ans,dp[n-1][m-1][i]);
        }

        return ans;
    }
};