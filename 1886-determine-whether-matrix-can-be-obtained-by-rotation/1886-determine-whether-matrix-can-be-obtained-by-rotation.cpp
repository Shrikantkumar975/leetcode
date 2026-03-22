class Solution {
public:
    void rot(vector<vector<int>> &mat){
        vector<vector<int>> v=mat;
        int n=mat.size();

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v[j][n-i-1]=mat[i][j];
            }
        }
        
        mat=v;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i=0;i<4;i++){
            rot(mat);
            if(mat==target) return true;
        }

        return false;
    }
};