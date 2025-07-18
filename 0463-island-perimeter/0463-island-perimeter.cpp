class Solution {
public:
    // void dfs(vector<vector<int>> &grid,int i,int j,int r,int c,int& count){
    //     if(i==r || j==c || i<0 || j<0 || grid[i][j] == 0){
    //         count++;
    //         return;
    //     }

    //     if(grid[i][j]==-1) return;

    //     grid[i][j] = -1;

    //     dfs(grid,i,j+1,r,c,count);
    //     dfs(grid,i-1,j,r,c,count);
    //     dfs(grid,i,j-1,r,c,count);
    //     dfs(grid,i+1,j,r,c,count);
    // }

    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(grid[i][j]==0) continue;

               if(j+1==c || grid[i][j+1]==0){
                count++;
               }

               if(i-1<0 || grid[i-1][j]==0){
                count++;
               }

               if(j-1<0 || grid[i][j-1]==0) count++;
               if(i+1==r || grid[i+1][j]==0) count++;
            }
        }
        return count;
    }
};