class Solution {
public:
    int t[201][1001];
    int solve(vector<int> &nums,int idx,int target){
        if(target==0) return 1;
        if(idx>=nums.size() || target<0) return 0;

        if(t[idx][target]!=-1) return t[idx][target];

        int take =solve(nums,0,target-nums[idx]);
        int skip = solve(nums,idx+1,target);

        return t[idx][target]=take+skip;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        memset(t,-1,sizeof(t));
        
        return solve(nums,0,target);
    }
};