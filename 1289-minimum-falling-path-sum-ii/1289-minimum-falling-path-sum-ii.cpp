class Solution {
public:


    int path(vector<vector<int>> &memo,vector<vector<int>>&grid,int i,int j){
        if(i==0){
            memo[i][j] = grid[i][j];
            return memo[i][j];
        }

        if(memo[i][j]!=INT_MAX){
            return memo[i][j];
        }

        for(int k=0;k<grid.size();k++){
            if(k!=j)
                memo[i][j] = min(memo[i][j],path(memo,grid,i-1,k));
        }

        return memo[i][j]+=grid[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX;
        int n=grid.size();

        vector<vector<int>> memo(n,vector<int>(n,INT_MAX));


        for(int j=0;j<n;j++){
            memo[n-1][j] = min(memo[n-1][j],path(memo,grid,n-1,j));
            mini = min(mini,memo[n-1][j]);
        }


        return mini;
    }
};