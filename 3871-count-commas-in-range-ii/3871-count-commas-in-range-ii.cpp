class Solution {
public:
    long long countCommas(long long n) {
        long long answer=0;
        int comma = 1;
        long long lower = 1000;

        while(lower<=n){
            long long upper = lower*1000 -1;
            if(upper > n) upper = n;

            answer += (upper - lower + 1)* comma;

            lower*=1000;
            comma++;
        }

        return answer;
    }
};