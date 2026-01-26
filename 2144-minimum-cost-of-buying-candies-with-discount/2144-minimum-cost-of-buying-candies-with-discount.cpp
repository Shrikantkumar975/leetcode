class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();

        int m=cost.size()/3;

        if(m==0){
            if(n==2) return cost[0]+cost[1];
            else return cost[0];
        }

        int ans=0;
        int i;
        
        for(i=cost.size()-1;i>=2;i-=3){
            ans+=cost[i]+cost[i-1];
        }

        if(i>=0){
            if(i==1) ans+=cost[0]+cost[1];
            else ans+=cost[0];
        }

        return ans;
    }
};