class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int curri = 0;
        int currj = 0;
        int dir = 0;

        set<pair<int,int>> mpp;
        int ans = 0;

        for(int i=0;i<obstacles.size();i++){
            mpp.insert({obstacles[i][0],obstacles[i][1]});
        }

        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1) dir= (dir+1)%4;
            else if(commands[i]==-2) dir = (dir+3)%4;
            else{
                int n = commands[i];
                if(dir==0){
                    while(n>0 && mpp.find({curri,currj+1})==mpp.end()){
                        currj = currj+1;
                        n--;
                    }
                }
                else if(dir==1){
                    while(n>0 && mpp.find({curri+1,currj})==mpp.end()){
                        curri = curri+1;
                        n--;
                    }
                }
                else if(dir==2){
                    while(n>0 && mpp.find({curri,currj-1})==mpp.end()){
                        currj = currj-1;
                        n--;
                    }
                }
                else if(dir==3){
                    while(n>0 && mpp.find({curri-1,currj})==mpp.end()){
                        curri = curri-1;
                        n--;
                    }
                }
                ans= max(ans,curri*curri + currj*currj);
            }
        }

        return ans;
    }
};