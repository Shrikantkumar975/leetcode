class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reached = nums.size()-1;

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]+i>=reached) reached = i;
        }

        if(reached == 0) return true;
        else return false;
    }
};