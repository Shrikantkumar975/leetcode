class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        
        int curr = 0;

        int count= 0;
        for(int i=0;i<nums.size()-1;i++){
            if(curr+nums[i]>=total-(curr+nums[i])) count++;

            curr+=nums[i];
        }

        return count;

    }
};