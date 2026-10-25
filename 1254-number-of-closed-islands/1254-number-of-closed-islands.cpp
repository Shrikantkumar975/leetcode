class Solution {
public:

    int n,m;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    void bfs(vector<vector<int>> &grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int curri = q.front().first;
            int currj = q.front().second;

            grid[curri][currj]=1;

            q.pop();

            for(int i=0;i<4;i++){
                int ni = curri + dx[i];
                int nj = currj + dy[i];

                if(ni<0 || ni==n || nj < 0 || nj == m || grid[ni][nj]==1){
                    continue;
                }

                q.push({ni,nj});
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0)
                bfs(grid,i,j);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }



        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                count++;
                bfs(grid,i,j);
                }
            }
        }


        return count;
    }
};