class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mpp;

        for(auto &m: reservedSeats){
            if(m[1]==1 || m[1]==10) continue;

            if(mpp.find(m[0]-1)==mpp.end()) mpp[m[0]-1].resize(10, 0);
            mpp[m[0]-1][m[1]-1]=1;
        }

        int count=(n-mpp.size())*2;

        for(auto m: mpp){
            auto v1 = m.second;

            if(v1[1]==0 && v1[2]==0 && v1[3]==0 && v1[4]==0){
                count++;
                v1[1]=1;
                v1[2]=1;
                v1[3]=1;
                v1[4]=1;
            }

            if(v1[3]==0 && v1[4]==0 && v1[5]==0 && v1[6]==0){
                count++;
                v1[3]=1;
                v1[4]=1;
                v1[5]=1;
                v1[6]=1;
            }
            if(v1[5]==0 && v1[6]==0 && v1[7]==0 && v1[8]==0){
                count++;
                v1[5]=1;
                v1[6]=1;
                v1[7]=1;
                v1[8]=1;
            }
        }

        return count;
    }
};