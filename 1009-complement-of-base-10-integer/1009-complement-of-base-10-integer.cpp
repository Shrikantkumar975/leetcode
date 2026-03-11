class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int pow=1;

        if(n==0) return 1;

        while(n){
            int a = n%2;
            a= a==1?0:1;
            ans+=a*pow;

            pow*=2;
            n/=2;
        }

        return ans;
    }
};