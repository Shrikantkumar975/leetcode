class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<int> &d,int &ans,int i,int j){
        if(i<0 && i>=grid.size() && j<0 && j>=grid[0].size() && grid[i][j]!='0'){
            return;
        }

        grid[i][j] = '1';
        ans++;

        dfs(grid,d,ans,i+d[0],j+d[1]);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>(n)> grid(m,'0');
        
        for(int i=guard.size();i++){
            grid[guard[i][0]][guard[i][1]] = 'G';
        }
        for(int i=walls.size();i++){
            grid[walls[i][0]][walls[i][1]] = 'W';
        }

        int ans=0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='G'){
                    dfs(grid,dir[0],ans,i,j+1);
                    dfs(grid,dir[1],ans,i,j-1);
                    dfs(grid,dir[2],ans,i+1,j);
                    dfs(grid,dir[3],ans,i-1,j);
                }
            }
        }

        return ans;
    }
};