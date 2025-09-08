class Solution {
public:

    bool check(int a,int b){
        // int got = true;

        while(a){
            if(a%10 == 0){
                return false;
            }
            a/=10;
        }

        while(b){
            if(b%10 == 0){
                return false;
            }
            b/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int one = true;
        int a,b;
        if(n%2==0){
            a=b=n/2;
        }
        else{
            a=n/2 +1;
            b=n/2;
        }
        while(true){
            if(check(a,b)){
                return {a,b};
            }
            a++;
            b--;
        }

        return {};
    }
};