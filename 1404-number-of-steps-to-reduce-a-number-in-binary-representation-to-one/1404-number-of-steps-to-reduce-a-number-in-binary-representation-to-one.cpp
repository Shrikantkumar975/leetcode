class Solution {
public:
long long des(string s) {
    long long decimal = 0;

    for (int i = 0; i < s.length(); i++) {
        decimal = decimal * 2 + (s[i] - '0');
    }

    return decimal;
}
    int numSteps(string s) {
        int count = 0;
        long long a = des(s);
        while(a > 1){

        if(a%2== 0){
            a=a>>1;
        }
        else{
            a+=1;
        }
            count++;
        }
        return count;
    }
};