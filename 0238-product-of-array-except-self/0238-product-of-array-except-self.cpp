class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num =1;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) num*=nums[i];
            else zeroCount++;;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                nums[i] = 0; // More than 1 zero → all zero
            } else if (zeroCount == 1) {
                nums[i] = (nums[i] == 0 ? num : 0);
            } else {
                nums[i] = num / nums[i]; // still division
            }
        }

        return nums;
    }
};