class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> v(nums.size(),0);
        int mini = INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            v[i]=min(mini,nums[i]);
            mini = v[i];
        }

        int maxi = INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            if(maxi - v[i] <= k) return i;
        }

        return -1;
    }
};