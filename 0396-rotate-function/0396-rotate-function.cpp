class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        vector<int> ans(nums.size(),0);

        // ans[0]=0;
        for(int i=1;i<nums.size();i++){
            ans[0]+=nums[i]*i;
        }

        for(int i=1;i<ans.size();i++){
            ans[i]=ans[i-1]+sum-nums.size()*nums[nums.size()-i];
        }

        return *max_element(ans.begin(),ans.end());
    }
};