class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k%=n;

        if(k==0) return true;

        vector<vector<int>> v = mat;

        for(int i=0;i<m;i++){
            int l=0;
            if(i%2==0){
                for(int j=k;j<n;j++){
                    v[i][l]=mat[i][j];
                    l++;
                }

                for(int j=0;j<k;j++){
                    v[i][l]=mat[i][j];
                    l++;
                }
            }else{
                for(int j = n - k; j < n; j++){
                    v[i][l++] = mat[i][j];
                }
                for(int j = 0; j < n - k; j++){
                    v[i][l++] = mat[i][j];
                }
            }
        }

        return v==mat;
    }
};