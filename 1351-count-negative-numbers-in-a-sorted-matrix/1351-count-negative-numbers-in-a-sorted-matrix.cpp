class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=0;

        for(int i=0;i<grid.size();i++){
            int ans = grid[i].size();
            int low = ans-1;
            int high =0;

            while(high<=low){
                int mid = (high+low)/2;

                if(grid[i][mid]<0){
                    ans=mid;
                    low = mid-1;
                }else{
                    high = mid+1;
                }
            }
            // if(ans==-1 && grid[i][high]<0) ans=high;

            n+=grid[i].size()-ans;
        }

        return n;
    }
};