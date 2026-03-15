class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod =1;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) prod*=nums[i];
            else zeroCount++;;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 1) {
                nums[i] = 0; 
            } else if (zeroCount == 1) {
                nums[i] = (nums[i] == 0 ? prod : 0);
            } else {
                nums[i] = prod / nums[i];
            }
        }

        return nums;
    }
};