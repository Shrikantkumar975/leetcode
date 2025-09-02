class Solution {
public:
    int numberOfPairs(vector<vector<int>>& point) {
        int n = point.size();
        int result =0;
        sort(point.begin(), point.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1]; // y in descending
        return a[0] < b[0];                   // x in ascending
    });


        for(int i=0;i<n-1;i++){
            int x1 = point[i][0];
            int y1 = point[i][1];
            int maxY = INT_MIN;

            for(int j=i+1;j<n;j++){

                int x2 = point[j][0];
                int y2 = point[j][1];

                if(y2>y1) continue;

                if(y2>maxY){
                    result++;
                    maxY=y2;
                }

            }
        }

        return result;
    }
};