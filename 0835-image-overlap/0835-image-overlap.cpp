class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int> mpp;
        int maxi=0;
        int n = img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    for(int a=0;a<n;a++){
                        for(int b=0;b<n;b++){
                            if(img2[a][b]==1){
                                mpp[{a-i,b-j}]++;
                            }
                        }
                    }
                }
            }
        }

        for(auto m: mpp){
            maxi = max(maxi,m.second);
        }

        return maxi;
    }
};