class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxLength = 0;
        
        int ans =0;

        for(int i=0;i<dimensions.size();i++){
            int a = dimensions[i][0];
            int b = dimensions[i][1];

            double maxi = sqrt(a*a + b*b);
            if(maxi > maxLength){
                maxLength = maxi;
                ans = a*b;
            }
            else if(maxi == maxLength && (a*b)>ans ){
                ans = a*b;
            }
        }

        return ans; 
    }
};