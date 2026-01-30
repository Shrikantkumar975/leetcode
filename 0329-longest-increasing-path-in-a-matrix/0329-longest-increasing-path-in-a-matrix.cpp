class Solution {
public:
    vector<vector<int>> dp;

    int dfs(vector<vector<int>> &matrix,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];

        int count=1;

        if(j+1<matrix[0].size() && matrix[i][j]<matrix[i][j+1])
        count = max(count,1+dfs(matrix,i,j+1));
        if(i+1<matrix.size() && matrix[i][j]<matrix[i+1][j])
        count = max(count,1+dfs(matrix,i+1,j));
        if(j-1>=0 && matrix[i][j]<matrix[i][j-1])
        count = max(count,1+dfs(matrix,i,j-1));
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j])
        count = max(count,1+dfs(matrix,i-1,j));

        return dp[i][j] = count;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));

        int maxi=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi = max(maxi,dfs(matrix,i,j));
            }
        }

        return maxi;
    }
};