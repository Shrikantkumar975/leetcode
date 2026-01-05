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

        long long sum = accumulate(v.begin(),v.end(),0ll);

        if(count%2==0) return sum;

        sort(v.begin(),v.end());
        sum-=2*v[0];

        return sum;
    }
};