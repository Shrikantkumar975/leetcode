class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = (n*(n+1))/2;

        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=matrix[i][j];
            }
            if(c!=sum) return false;
        }

        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=matrix[j][i];
            }
            if(c!=sum) return false;
        }

        return true;
    }
};