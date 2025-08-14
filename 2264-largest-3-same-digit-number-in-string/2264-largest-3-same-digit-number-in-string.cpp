class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = ' ';
        int count = 1;
        char last = num[num.size()-1];
        for(int i=num.size()-2;i>=0;i--){

            if(num[i] == last){
                count++;
            }else{
                count =1;
                last = num[i];
            }

            if(count >= 3){
                ans = max(ans,last);
            }
        }
        return ans==' '?"":string(3,ans);
    }
};