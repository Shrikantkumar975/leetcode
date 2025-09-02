class Solution {
public:
    int numberOfPairs(vector<vector<int>>& point) {
        int n = point.size();
        int result =0;

        for(int i=0;i<n;i++){
            int x1 = point[i][0];
            int y1 = point[i][1];

            for(int j=0;j<n;j++){
                if(j==i) continue;

                int x2 = point[j][0];
                int y2 = point[j][1];
                

                if(x1<=x2 && y1>=y2){
                    int h = 0;  
                    for(int k=0;k<n;k++){
                        if(k==i || k==j) continue;

                        int x3 = point[k][0];
                        int y3 = point[k][1];

                        if(x3>=x1 && x3<=x2 && y3<=y1 && y3>=y2){
                            h=1;
                            break;
                        }
                    }
                    if(h!=1){
                        result++;
                    }
                }

            }
        }

        return result;
    }
};