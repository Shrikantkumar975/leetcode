class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=1;
        int mini=INT_MAX;

        if(nums[0]>=target) return 1;
        int sum = nums[0];
        while(i<=j && j<nums.size()){
            if(sum+nums[j]<target){
                sum+=nums[j];
                j++;
            }else{
                mini = min(mini,j-i+1);
                sum-=nums[i];
                i++;
            }
        }

        if(mini == INT_MAX) return 0;
        return mini;

    }
};