class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;

        for(char ch: moves){
            if(ch == 'U') {
                i-=1;
            }else if(ch == 'D'){
                i+=1;
            }else if(ch == 'R'){
                j+=1;
            }else{
                j-=1;
            }
        }

        return i==0 && j==0;
    }
};