class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> v;
        int i=0;
        int j=0;
        int dir = 0;
        int count=0;

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        v.push_back(matrix[i][j]);
        matrix[i][j]=-101;
        count++;

        while(i<m && j<n){
            if(count == n*m) break;
            if(i+dx[dir]<0 || i+dx[dir]>=m || j+dy[dir]<0 || j+dy[dir]>=n || matrix[i+dx[dir]][j+dy[dir]]==-101){
                dir=(dir+1)%4;
                continue;
            }
            i=i+dx[dir];
            j=j+dy[dir];

            v.push_back(matrix[i][j]);
            matrix[i][j]=-101;
            count++;
        }
        return v;
    }
};