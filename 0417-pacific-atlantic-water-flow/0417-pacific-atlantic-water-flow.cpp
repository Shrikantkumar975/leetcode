class Solution {
public:
    int m, n;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {
        vis[i][j] = true;

        for (int k=0;k<4;k++) {
            int x =i+dx[k], y = j + dy[k];

            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || heights[x][y] < heights[i][j])
                continue;

            dfs(x, y, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> arr1(m, vector<bool>(n, false));
        vector<vector<bool>> arr2(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++)
            dfs(0, j, heights, arr1);
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, arr1);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, arr2);
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, arr2);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr1[i][j] && arr2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};