class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(3, 0)));

        // (0,0)
        if(grid[0][0]=='.') v[0][0][0]++;
        else if(grid[0][0]=='X') v[0][0][1]++;
        else v[0][0][2]++;

        int ans = 0;

        if(v[0][0][1]>0 && v[0][0][1]==v[0][0][2]) ans++;

        // first column
        for(int i=1;i<n;i++){
            for(int k=0;k<3;k++){
                v[i][0][k] = v[i-1][0][k];
            }

            if(grid[i][0]=='.') v[i][0][0]++;
            else if(grid[i][0]=='X') v[i][0][1]++;
            else v[i][0][2]++;

            if(v[i][0][1]>0 && v[i][0][1]==v[i][0][2]) ans++;
        }

        // first row
        for(int j=1;j<m;j++){
            for(int k=0;k<3;k++){
                v[0][j][k] = v[0][j-1][k];
            }

            if(grid[0][j]=='.') v[0][j][0]++;
            else if(grid[0][j]=='X') v[0][j][1]++;
            else v[0][j][2]++;

            if(v[0][j][1]>0 && v[0][j][1]==v[0][j][2]) ans++;
        }

        // rest
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){

                for(int k=0;k<3;k++){
                    v[i][j][k] = v[i-1][j][k] + v[i][j-1][k] - v[i-1][j-1][k];
                }

                if(grid[i][j]=='.') v[i][j][0]++;
                else if(grid[i][j]=='X') v[i][j][1]++;
                else v[i][j][2]++;

                if(v[i][j][1]>0 && v[i][j][1]==v[i][j][2]){
                    ans++;
                }
            }
        }

        return ans;
    }
};