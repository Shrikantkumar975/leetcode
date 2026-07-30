class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int size=word.size();
        int i=1;

        while(size>0){
            if(size>=8){
                ans+=8*i++;
                size-=8;
            }else{
                ans+=size*i++;
                size=0;
            }
        }

        return ans;
    }
};