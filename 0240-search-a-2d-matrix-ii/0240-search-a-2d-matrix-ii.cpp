class Solution {
public:
    int binarySearch(vector<int>&mat,int x){
        int low =0;
        int high = mat.size()-1;

        while(low<=high){
            long mid = low + (high-low)/2;

            if(x == mat[mid]) return mid;
            else if(x<mat[mid]) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ind= -1;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
               int a = binarySearch(matrix[i],target);
               if(a!=-1) ind = a;
        }

        return ind!=-1;
    }
};