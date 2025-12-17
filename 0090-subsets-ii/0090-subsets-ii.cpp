class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,ans,temp,0);

        return ans;
    }

    void solve(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,int start){
        if(start == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[start]);
        solve(nums,ans,temp,start+1);
        temp.pop_back();

        int next=start+1;
        while(next<nums.size() && nums[next]==nums[start]) next++;
        
        solve(nums,ans,temp,next);
    }
};