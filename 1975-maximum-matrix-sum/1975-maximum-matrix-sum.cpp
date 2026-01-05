class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int count = 0;
        vector<int> v;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]<0) count++;
                v.push_back(abs(mat[i][j]));
            }
        }

        int sum = accumulate(v.begin(),v.end(),0);

        if(count%2==0) return sum;

        count%=2;
        sort(v.begin(),v.end());
        int i=0;
        while(count--){
            sum-=2*v[i];
        }

        return sum;
    }
};