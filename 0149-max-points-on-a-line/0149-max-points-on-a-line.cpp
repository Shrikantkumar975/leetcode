class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n==1) return 1;
        int result =0;
        for(int i=0;i<n;i++) {
            unordered_map<double , int> mpp;
                for(int j=0;j<n;j++){
                    if(j!=i){
                        int dy = points[j][1]-points[i][1];
                        int dx = points[j][0]-points[i][0];
                        double q = atan2(dy,dx);
                        mpp[q]++;
                    }
                }

                int count=0;
                for(auto m: mpp){
                    count = max(count,m.second);
                }
                result = max(result,count+1);
        }
        return result;
    }
};