class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;

        int turn =1;

        while(true){
            if(turn){
                if(alice>0 && alice<=n){
                    n-=alice;
                    alice-=2;
                }else{
                    return false;
                }
                turn=0;
            }else{
                if(bob>0 && bob<=n){
                    n-=bob;
                    bob-=2;
                }else{
                    return true;
                }
                turn=1;
            }
        }
    }
};