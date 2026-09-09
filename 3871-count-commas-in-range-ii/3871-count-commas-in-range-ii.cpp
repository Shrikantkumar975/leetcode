class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long curr = 1000;

        int base = n%1000;

        while(curr<=n){
            ans+=(n-curr)+1;
            curr*=1000;
        }

        return ans;
    }
};