class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int ans =0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i>0 && matrix[i][j]!=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }

            vector<int> v = matrix[i];
            sort(v.begin(),v.end(),greater<int>());

            for(int j=0;j<v.size();j++){
                ans=max(ans,v[j]*(j+1));
            }
        }

        return ans;
    }
};