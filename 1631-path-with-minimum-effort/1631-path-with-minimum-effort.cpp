class Solution {
public:
using T = tuple<int,int,int>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        // vector<vector<int>> parent(n,vector<int>(m));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         parent[i][j] = 
        //     }
        // }
        auto isSafe = [&](int x,int y){
            if(x<n && x>=0 && y<m && y>=0) return true;

            return false;
        };

        priority_queue<T,vector<T>,greater<T>> pq;

        pq.push({0,0,0});
        distance[0][0]=0;
        vector<int> dx={0,-1,0,1};
        vector<int> dy={1,0,-1,0};

        while(!pq.empty()){
            auto [d,x,y] = pq.top();
            pq.pop();

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(isSafe(nx,ny) && abs(heights[nx][ny]-heights[x][y]) < distance[nx][ny] ){
                    distance[nx][ny]=abs(heights[nx][ny]-heights[x][y]);
                    pq.push({distance[nx][ny],nx,ny});
                }
            }
        }

        return distance[n-1][m-1];

    }
};