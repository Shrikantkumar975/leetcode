class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin(),nums.end(),0LL);
        
        long long curr = 0;

        int count= 0;
        for(int i=0;i<nums.size()-1;i++){
            long long num = curr+nums[i];
            if(num>=total-num) count++;

            curr+=nums[i];
        }

        return count;

    }
};