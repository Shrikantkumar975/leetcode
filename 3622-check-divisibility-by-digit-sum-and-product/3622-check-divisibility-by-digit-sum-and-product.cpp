class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prd= 1;
        int temp=n;

        while(n){
            sum+=n%10;
            prd*=n%10;

            n/=10;
        }

        return temp%(sum+prd)==0;
    }
};