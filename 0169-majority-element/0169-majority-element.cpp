class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand =0,lead=0;

        for(int i=0;i<nums.size();i++){
            if(lead == 0) cand=nums[i];
            if(cand == nums[i]) lead++;
            else lead--;
        }

        return cand;
    }
};