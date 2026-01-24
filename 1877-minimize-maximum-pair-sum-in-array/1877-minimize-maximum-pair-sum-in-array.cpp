class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int maxi = nums[0] + nums[nums.size()-1];

        int n= nums.size();

        for(int i=1;i<n/2;i++){
            maxi = max(maxi,nums[i]+nums[n-i-1]);
        }

        return maxi;
    }
};