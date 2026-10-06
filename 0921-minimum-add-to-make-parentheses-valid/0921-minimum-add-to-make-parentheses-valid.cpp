class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;
        int ans=0;

        for(char c: s){
            if(c=='(') open++;
            else close++;

            if(close>open){
                ans+=close-open;
                open=close;
            }
        }

        if(open>close){
            ans+=open-close;
        }

        return ans;
    }
};