class Solution {
public:
    int ans[46];
    int ways(int curr,int tar){
        if(curr>tar) return 0;

        if(ans[curr]!=-1) return ans[curr];
        
        if(curr==tar) return 1;


        return ans[curr] = ways(curr+1,tar) + ways(curr+2,tar);
    }

    int climbStairs(int n) {
        memset(ans,-1,sizeof(ans));
        ans[n]=ways(0,n);

        return ans[n];
    }
};