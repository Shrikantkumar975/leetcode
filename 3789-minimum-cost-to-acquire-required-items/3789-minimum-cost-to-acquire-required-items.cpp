class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL*costBoth*max(need1,need2);

        long long option1 = 1LL*cost1*need1 + 1LL*cost2*need2;

        long long option2 = 1LL*costBoth*min(need1,need2);

        if(need1<need2){
            option2+=1LL*cost2*(need2-need1);
        }else{
            option2+=1LL*cost1*(need1-need2);
        }

        ans = min(ans,option1);

        return min(ans,option2);
    }
};