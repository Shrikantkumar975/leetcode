class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        vector<int> count;
        int max = -1;
        int cn = 0;

        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) c++;
            }
            if(c>cn){
                cn = c;
                max = i;
            }
        }
        return {max,cn};
    }
};