class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums.size()-1;
        int i=reach-1;

        while(i>=0){
            if(i+nums[i]>=reach){
                reach =i;
            }
            i--;
        }

        return reach==0;
    }
};