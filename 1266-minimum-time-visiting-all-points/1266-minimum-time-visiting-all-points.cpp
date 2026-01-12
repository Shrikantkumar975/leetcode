class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int currX=points[0][0];
        int currY=points[0][1];

        for(int i=1;i<points.size();i++){
            int changeX = abs(points[i][0]-currX);
            int changeY = abs(points[i][1]-currY);

            ans+= min(changeX,changeY) + abs(changeX-changeY);

            currX = points[i][0];
            currY = points[i][1];
        }

        return ans;
    }
};