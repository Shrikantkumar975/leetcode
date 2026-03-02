class Solution {
public:
    int res=0;

    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    void findPath(vector<vector<int>> &grid,int &total, int si,int sj,int count){
        if(si>=grid.size() || sj>=grid[0].size() || si<0 || sj<0) return;

        if(grid[si][sj]==-1) return;

        if(grid[si][sj]==2 && count==total){
            res++;
            return;
        }

        int temp =grid[si][sj];
        grid[si][sj]=-1;

        for(int i=0;i<4;i++){
            int ci = si+dx[i];
            int cj = sj+dy[i];

            findPath(grid,total,ci,cj,count+1);
        }

        grid[si][sj]=temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int totalpath = 0;
        int si = -1;
        int sj =-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1) totalpath++;
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
            }
        }

        findPath(grid,totalpath,si,sj,1);

        return res;
    }
};