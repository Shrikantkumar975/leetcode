class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c= matrix[0].size();
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(j-1<0){
                    matrix[i][j] += min(matrix[i-1][j+1],matrix[i-1][j]);
                }
                else if(j+1==c){
                    matrix[i][j] += min(matrix[i-1][j-1],matrix[i-1][j]);
                }
                else{
                    matrix[i][j] += min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1]));
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<c;i++){
            ans = min(ans,matrix[r-1][i]);
        }

        return ans;
    }
};