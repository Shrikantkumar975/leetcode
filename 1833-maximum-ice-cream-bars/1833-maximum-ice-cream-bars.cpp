class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i=0;
        int maxi=0;

        sort(costs.begin(),costs.end());

        while(coins>0 && i<costs.size()){
            if(costs[i]<=coins){
                maxi++;
                coins-=costs[i];
                i++;
            }else{
                break;
            }
        }

        return maxi;
    }
};