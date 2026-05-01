class Solution {
public:
    int climbStairs(int n) {

        if(n<=2) return n;

        int t1=1;
        int t2=1;

        for(int i=2;i<=n;i++){
            int t3=t1+t2;
            t1=t2;
            t2=t3;
        }

        return t2;
    }
};