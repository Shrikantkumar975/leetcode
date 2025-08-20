class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int cols =matrix[0].size();
        vector<vector<int>> v(row+1,vector<int>(cols+1,0));
    int maxSide =0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=cols;j++){
                if(matrix[i-1][j-1] == '1'){
                    v[i][j] = 1 + min({v[i-1][j-1],v[i-1][j],v[i][j-1]});
                    maxSide = max(maxSide,v[i][j]);
                }else{
                    v[i][j] = 0;
                }
            }
        }

        return maxSide*maxSide;
    }
};