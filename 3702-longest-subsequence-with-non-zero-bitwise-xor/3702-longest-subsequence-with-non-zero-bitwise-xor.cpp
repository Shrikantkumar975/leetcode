class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum==0) return 0;

        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            curr^=nums[i];
        }

        if(curr==0) return nums.size()-1;

        return nums.size();
    }
};