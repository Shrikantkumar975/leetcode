class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        int curr=0;

        for(int i=1;i<nums.size();i++){
            curr+=nums[i]*i;
        }
        int maxi=curr;

        for(int i=1;i<nums.size();i++){
            curr=curr+sum-nums.size()*nums[nums.size()-i];
            maxi =max(maxi,curr);
        }

        return maxi;

        // return *max_element(ans.begin(),ans.end());
    }
};