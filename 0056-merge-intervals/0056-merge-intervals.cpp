class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        if(intervals.empty()) return v;
        
        sort(intervals.begin(),intervals.end());

        v.push_back(intervals[0]);
        int i=0;

        for(int j=1;j<intervals.size();j++){
            if(v[i][1]>=intervals[j][0]){
                v[i][1] = max(intervals[j][1],v[i][1]);
            }
            else {
                v.push_back(intervals[j]);
                i++;
            }
        }

        return v;

        

    }
};