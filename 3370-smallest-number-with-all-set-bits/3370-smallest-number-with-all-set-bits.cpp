class Solution {
public:
    int smallestNumber(int n) {
        string s;
        while(n>0){
            if(n%2==0){
                s+='0';
            }else(
                s+='1'
            );
            n/=2;
        }
        n = s.size();
        int num=0;
        int i=0;
        while(i<n){
           num+=pow(2,i);
           i++;     
        }

        return num;

    }
};