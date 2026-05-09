class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k1) {
        int noOfLayersC = grid[0].size()/2;
        int noOfLayersR = grid.size()/2;

        int noOfLayers = min(noOfLayersC,noOfLayersR);
        int n = grid.size();
        int m = grid[0].size();

        if(k1==0) return grid;

        for(int c=0;c<noOfLayers;c++){
            int top = c;
            int bottom = n-c-1;
            int left = c;
            int right = m-c-1;
            vector<int> arr;

            for(int i=left;i<=right;i++){
                arr.push_back(grid[top][i]);
            }
            // top++;

            for(int i=top+1;i<=bottom;i++){
                arr.push_back(grid[i][right]);
            }
            // right--;
            if (top < bottom)
                for(int i=right-1;i>=left;i--){
                    arr.push_back(grid[bottom][i]);
                }
            // bottom--;
            
            if(left < right)
                for(int i=bottom-1;i>top;i--){
                    arr.push_back(grid[i][left]);
                }

            int currL = arr.size();

            int k = k1%currL;
            if(k==0) continue;

            // reverse(arr.begin(),arr.begin()+k);
            // reverse(arr.begin()+k,arr.end());
            // reverse(arr.begin(),arr.end());

            rotate(arr.begin(),arr.begin()+k,arr.end());

            int j=0;

            for(int i=left;i<=right;i++){
                grid[top][i]=arr[j++];
            }
            // top++;

            for(int i=top+1;i<=bottom;i++){
                grid[i][right]=arr[j++];
            }
            // right--;
            if (top < bottom)
                for(int i=right-1;i>=left;i--){
                    grid[bottom][i]=arr[j++];
                }
            // bottom--;
            
            if(left < right)
                for(int i=bottom-1;i>top;i--){
                    grid[i][left]=arr[j++];
                }
        }

        return grid;
    }
};

//takes 45:49 mins