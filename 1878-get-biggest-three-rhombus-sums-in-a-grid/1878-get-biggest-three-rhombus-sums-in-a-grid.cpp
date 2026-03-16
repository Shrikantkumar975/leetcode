class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        set<int> st;

        int i = 0;

        while(i < min(n,m)){

            for(int j = 0; j + i < n; j++){
                for(int k = 0; k + i < m; k++){

                    if(i == 0){
                        st.insert(grid[j][k]);
                        continue;
                    }

                    int r = i/2;

                    int cx = j + r;
                    int cy = k + r;

                    if(cx-r < 0 || cx+r >= n || cy-r < 0 || cy+r >= m)
                        continue;

                    int sum = 0;

                    int x = cx - r;
                    int y = cy;

                    for(int t = 0; t < r; t++)
                        sum += grid[x+t][y+t];

                    for(int t = 0; t < r; t++)
                        sum += grid[cx+t][cy+r-t];

                    for(int t = 0; t < r; t++)
                        sum += grid[cx+r-t][cy-t];

                    for(int t = 0; t < r; t++)
                        sum += grid[cx-t][cy-r+t];

                    st.insert(sum);
                }
            }

            i += 2;
        }

        vector<int> ans;

        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++)
            ans.push_back(*it);

        return ans;
    }
};