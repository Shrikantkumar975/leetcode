class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long ans =0;

        long long count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                count=0;
            }else{
                count++;
                ans=(ans + count)%MOD;
            }
        }
        return ans;
    }
};