class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num=1;
        for(int i=0;i<k;i++){
            num=num%k;
            if(num%k==0) return i+1;
            num=num*10+1;
        }

        return -1;
    }

};