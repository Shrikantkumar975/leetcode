class Solution {
public:
    int minimumArea(int row,int n,int col,int m,vector<vector<int>> &grid){
        int minRow = n;
        int maxRow = -1;
        int minCol = m;
        int maxCol = -1;

        for(int i=row;i<n;i++){
            for(int j=col;j<m;j++){
                if(grid[i][j] == 1){
                    minRow = min(minRow,i);
                    maxRow = max(maxRow,i);
                    minCol = min(minCol,j);
                    maxCol = max(maxCol,j);
                }
            }
        }

        if(maxCol == -1) return 0;

        return (maxRow - minRow + 1)*(maxCol - minCol+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = INT_MAX;
        //case-1

        for(int rowSplit=1;rowSplit<n;rowSplit++){
            for(int colSplit=1;colSplit<m;colSplit++){
                int top = minimumArea(0,rowSplit,0,m,grid);
                int bottomLeft = minimumArea(rowSplit,n,0,colSplit,grid);
                int bottomRight = minimumArea(rowSplit,n,colSplit,m,grid);

                res = min(res,top+bottomLeft+bottomRight);
            }
        }

        //case-2
        for(int rowSplit=1;rowSplit<n;rowSplit++){
            for(int colSplit=1;colSplit<m;colSplit++){
                int bottom = minimumArea(rowSplit,n,0,m,grid);
                int topLeft = minimumArea(0,rowSplit,0,colSplit,grid);
                int topRight = minimumArea(0,rowSplit,colSplit,m,grid);

                res = min(res,bottom+topLeft+topRight);
            }
        }

        //case-3
        for(int rowSplit = 1;rowSplit<n-1;rowSplit++){
            for(int secRowSplit = rowSplit+1;secRowSplit < n;secRowSplit++){
                int firstRec = minimumArea(0,rowSplit,0,m,grid);
                int secRec = minimumArea(rowSplit,secRowSplit,0,m,grid);
                int thirdRec = minimumArea(secRowSplit,n,0,m,grid);

                res = min(res,firstRec+secRec+thirdRec);
            }
        }

        //case-4
        for(int colSplit = 1;colSplit<m-1;colSplit++){
            for(int secColSplit = colSplit+1;secColSplit < m;secColSplit++){
                int firstRec = minimumArea(0,n,0,colSplit,grid);
                int secRec = minimumArea(0,n,colSplit,secColSplit,grid);
                int thirdRec = minimumArea(0,n,secColSplit,m,grid);

                res = min(res,firstRec+secRec+thirdRec);
            }
        }

        return res;
    }
};