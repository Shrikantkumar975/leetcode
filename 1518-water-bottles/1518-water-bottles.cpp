class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty =0;
        int ans = 0;

        while(numBottles>0){
            ans+=numBottles;

            empty+=numBottles;

            numBottles = empty/numExchange;
            empty%=numExchange;
            // numBottles/=numExchange;
        }

        return ans;
    }
};