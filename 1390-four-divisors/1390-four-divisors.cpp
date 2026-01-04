class Solution {
public:
    int countDivisor(int a,int &sum){
        int count=1;
        sum+=a;
        for(int i=1;i<a/2;i++){
            if(a%i==0){
                count++;
                sum+=i;
            }
        }
        return count;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int a: nums){
            int sum=0;
            if(countDivisor(a,sum)==4){
                ans+=sum;
            }
        }

        return ans;
    }


};