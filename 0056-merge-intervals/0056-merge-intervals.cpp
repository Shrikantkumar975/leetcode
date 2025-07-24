class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;

        if(intervals.size() == 0) return v;
        v.push_back(intervals[0]);
        int i=0;
        for(int j=1;j<intervals.size();j++){
            if(v[i][1]>=intervals[j][0]){
                v[i][1] = max(v[i][1],intervals[j][1]);
            }
            else{
                v.push_back(intervals[j]);
                i++;
            }
        }

        return v;
    }
};