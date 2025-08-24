class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;

         int r = grid.size();
         int c = grid[0].size();

         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    grid[i][j] = -1;
                }
            }
         }
            vector<int> dx = {0,-1,0,1};
            vector<int> dy = {1,0,-1,0};

         while(!q.empty()){
            int size = q.size();

            while(size--){
                auto node = q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];

                    if(x<r && y<c && x>=0 && y>=0 && grid[x][y]==-1){
                        grid[x][y] = grid[node.first][node.second] + 1;
                        q.push({x,y});
                    }
                }
            }
         }

         return grid;
    }
};