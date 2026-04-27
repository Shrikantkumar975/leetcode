class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    bool dfs(vector<vector<int>>& grid, int curri, int currj,
             vector<vector<int>>& dir, vector<vector<int>>& vis) {
        if (curri == grid.size()-1 && currj == grid[0].size()-1)
            return true;

        if (vis[curri][currj])
            return false;

        vis[curri][currj] = true;

        for (int d : dir[grid[curri][currj] - 1]) {
            int newi = curri+dx[d];
            int newj = currj+dy[d];
            if(d==0){
                if(newi<grid.size() && newj<grid[0].size() && newi>=0 && newj>=0){
                    if((grid[newi][newj]==1 || grid[newi][newj]==3 || grid[newi][newj]==5) && dfs(grid,newi,newj,dir,vis)){
                        return true;
                    }
                }
            }
            else if(d==1){
                if(newi<grid.size() && newj<grid[0].size() && newi>=0 && newj>=0){
                    if((grid[newi][newj]==2 || grid[newi][newj]==5 || grid[newi][newj]==6) && dfs(grid,newi,newj,dir,vis)){
                        return true;
                    }
                }
            }
            else if(d==2){
                if(newi<grid.size() && newj<grid[0].size() && newi>=0 && newj>=0){
                    if((grid[newi][newj]==1 || grid[newi][newj]==4 || grid[newi][newj]==6) && dfs(grid,newi,newj,dir,vis)){
                        return true;
                    }
                }
            }
            else{
                if(newi<grid.size() && newj<grid[0].size() && newi>=0 && newj>=0){
                    if((grid[newi][newj]==2 || grid[newi][newj]==3 || grid[newi][newj]==4) && dfs(grid,newi,newj,dir,vis)){
                        return true;
                    }
                }
            }

        }
            return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0, 2}, {1, 3}, {1, 2},
                                    {0, 1}, {2, 3}, {0, 3}};
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 5 || grid[n - 1][m - 1] == 4) {
            return false;
        }
        vector<vector<int>> vis(n, vector<int>(m, false));
        if (dfs(grid, 0, 0, dir, vis))
            return true;

        return false;
    }
};