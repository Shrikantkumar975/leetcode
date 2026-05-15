class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=0;
        if(nums.size()<=1) return false;

        while(i<nums.size()-2){
            if(nums[i]!=i+1) return false;
            i++;
        }

        if(nums[i]!=i+1 || nums[i+1]!=i+1) return false;

        return true;
    }
};