class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        for(int i=1;i<=12;i++){
            months[i]+=months[i-1];
        }

        int aAM = (arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
        int aAD = (arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');

        int aLM = (leaveAlice[0]-'0')*10+(leaveAlice[1]-'0');
        int aLD = (leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');

        int bAM = (arriveBob[0]-'0')*10+(arriveBob[1]-'0');
        int bAD = (arriveBob[3]-'0')*10+(arriveBob[4]-'0');

        int bLM = (leaveBob[0]-'0')*10+(leaveBob[1]-'0');
        int bLD = (leaveBob[3]-'0')*10+(leaveBob[4]-'0');

        int aA = months[aAM-1]+aAD;
        int aL = months[aLM-1]+aLD;

        int bA = months[bAM-1]+bAD;
        int bL = months[bLM-1]+bLD;

        cout<<months[11]<<" "<<aA<<" "<<aL<<" "<<bA<<" "<<bL;

        int mini = min(aL,bL);
        int maxi =  max(aA,bA);

        if(mini<maxi) return 0;

        return mini - maxi+1;
    }
};