class Solution {
public:
    int cycle=0;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    void dfs(vector<vector<char>> &grid,vector<vector<int>> &v,int curri,int currj,int pi,int pj){
        if(cycle) return;

        v[curri][currj]=1;

        for(int i=0;i<4;i++){
            int x = curri+dx[i];
            int y = currj+dy[i];

            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] != grid[curri][currj]) continue;

            if(x==pi && y==pj) continue;

            if(v[x][y]){
                cycle=true;
                return;
            }

            dfs(grid,v,x,y,curri,currj);
        }
    }


    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!v[i][j]) dfs(grid,v,i,j,-1,-1);
                if(cycle) break;
            }
        }

        return cycle;
    }
};