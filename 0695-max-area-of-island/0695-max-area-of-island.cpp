class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,int r,int c,int &count){
            if(i==r || j==c ||i<0 ||j<0 || grid[i][j]==0) return;
            count++;
            grid[i][j] = 0;
            
            dfs(grid,i,j+1,r,c,count);
            dfs(grid,i-1,j,r,c,count);
            dfs(grid,i,j-1,r,c,count);
            dfs(grid,i+1,j,r,c,count);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int count =0;
                if(grid[i][j]==1){
                dfs(grid,i,j,r,c,count);
                ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};