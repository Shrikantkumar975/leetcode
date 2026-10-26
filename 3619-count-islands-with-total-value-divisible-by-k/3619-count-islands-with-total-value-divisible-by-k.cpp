class Solution {
public:
    int n,m;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};

    void bfs(vector<vector<int>> &grid,int i, int j,int &curr,int k){

        queue<pair<int,int>> q;
        q.push({i,j});
        curr+=grid[i][j];
        grid[i][j]=0;

        while(!q.empty()){
            int curri = q.front().first;
            int currj = q.front().second;
            q.pop();


            for(int d=0;d<4;d++){
                int ni = curri + dx[d];
                int nj = currj + dy[d];

                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]>0){
                    curr+=grid[ni][nj];
                    curr%=k;

                    grid[ni][nj]=0;
                    q.push({ni,nj});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    int curr=0;
                    bfs(grid,i,j,curr,k);
                    
                    if(curr%k==0) ans++;
                }
            }
        }

        return ans;
    }
};