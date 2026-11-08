class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int totalServer = 0;
        vector<int> rows(grid.size(),0);
        vector<int> cols(grid[0].size(),0);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    totalServer++;
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        int canCom = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(rows[i]>=2 || cols[j]>=2){
                        canCom++;
                    }
                }
            }
        }


        return canCom;

    }
};