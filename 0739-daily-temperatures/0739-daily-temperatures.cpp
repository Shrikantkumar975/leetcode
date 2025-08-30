class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> s;
        vector<int> res(temp.size());

        for(int i=temp.size()-1;i>=0;i--){

            while(!s.empty() && s.top().first<=temp[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i]=s.top().second-i;
            }else{
                res[i]=0;
            }
            s.push({temp[i],i});
        }

        //brute force

        // for(int i=0;i<temp.size()-1;i++){
        //     int span=0;
        //     int j=i+1;
        //     while(j<temp.size()){
        //         if(temp[i]>=temp[j]){
        //             j++;
        //         }else break;
        //     }
        //     if(j != temp.size()) res[i] = j-i;
        //     else res[i] =0;
        // }
        return res;
    }
};