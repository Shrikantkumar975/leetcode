class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        int pow=1;

        while(a || b || carry){
            int currA = a%2;
            int currB = b%2;

            int sum = currA + currB + carry;
            
            ans+=(sum%2)*pow;
            carry=sum/2;

            pow*=2;

            a/=2;
            b/=2;
        }

        return ans;

    }
};