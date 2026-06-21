class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i=0;
        int maxi=0;

        sort(costs.begin(),costs.end());

        while(i<costs.size() && costs[i]<=coins ){
            maxi++;
            coins-=costs[i];
            i++;
        }

        return maxi;
    }
};