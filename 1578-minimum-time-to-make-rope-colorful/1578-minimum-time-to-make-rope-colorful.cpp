class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =accumulate(neededTime.begin(),neededTime.end(),0);
        int maxi = neededTime[0];
        int sum=0;
        int i =0;int j=1;
        while(j<colors.size()){
            if(colors[j]==colors[i]){
                maxi= max(maxi,neededTime[j]);
                j++;
            }else{
                sum+=maxi;
                maxi=neededTime[j];
                i=j;
                j++;
            }
        }
        sum+=maxi;
        return ans-sum;
    }
};