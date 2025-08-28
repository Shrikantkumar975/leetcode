class Solution {
public:

    void sortDiagonal(int row,int col , vector<vector<int>> &grid,bool as){
        vector<int> v;
        int n = grid.size();
        int m = grid[0].size();
        

        int r = row;
        int c = col;

        while(r<n && c<m){
            v.push_back(grid[r][c]);
            r++;
            c++;
        }

        if(as){
            sort(v.begin(),v.end());
        }else{
            sort(v.begin(),v.end(),greater<int>());
        }

        int i=0;
        r=row;
        c=col;
        while(r<n && c<m){
            grid[r][c] = v[i++];
            r++;
            c++;
        }
        
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        bool ascen = false;

        for(int row = 0;row<n;row++){
            sortDiagonal(row,0,grid,ascen);
        }

        ascen = true;
        for(int col = 1;col<m;col++){
            sortDiagonal(0,col,grid,ascen);
        }

        return grid;
    }
};