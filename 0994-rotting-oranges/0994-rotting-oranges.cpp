class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r = grid.size();
        int c = grid[0].size();
        int rotten =0;
        int fresh=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2){
                q.push({i,j});
                rotten++;
                }
                if(grid[i][j]==1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};
        int min =0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto node = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int newX = node.first + dx[i];
                    int newY = node.second + dy[i];

                    if(newX<r && newY<c && newX>=0 && newY>=0 && grid[newX][newY] == 1){
                        q.push({newX,newY});
                        grid[newX][newY] = 2;
                        fresh--;
                    }
                }
            }
            if(!q.empty()) min++;
        }

        if(fresh !=0) return -1;

        return min;
    }
};
