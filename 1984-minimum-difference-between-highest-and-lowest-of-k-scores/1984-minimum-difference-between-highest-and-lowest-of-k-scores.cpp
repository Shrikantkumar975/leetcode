class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int diff = INT_MAX;
        for(int i=0;i<=nums.size()-k;i++){
            for(int j=i+k-1;j<nums.size();j++){
                diff = min(diff,nums[j]-nums[i]);
            }
        }

        return diff;
    }
};