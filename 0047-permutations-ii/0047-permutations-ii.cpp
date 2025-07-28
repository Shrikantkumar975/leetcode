class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),0);

        solve(nums,ans,temp,used);

        return ans;
    }

    void solve(vector<int> nums,vector<vector<int>>&ans,vector<int>&temp,vector<int>&used){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])) continue;

            used[i]=1;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,used);
            temp.pop_back();
            used[i]=0;
        }
    }
};