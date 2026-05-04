class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int i=0;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int j=1;j<intervals.size();j++){
            if(ans[i][1]>=intervals[j][0]){
                ans[i][1] = max(ans[i][1],intervals[j][1]);
            }
            else{
                ans.push_back(intervals[j]);
                i++;
            }
        }
        return ans;
    }
};