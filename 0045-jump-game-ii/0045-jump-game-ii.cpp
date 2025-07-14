class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int j=0;
        int farthest = 0;
        int stop = 0;
        for(int i =0;i<nums.size()-1;i++){
            farthest = max(farthest,nums[i]+i);

            if(i==stop){
                j++;
            stop = farthest;
            }
        }  
        return j;
    }
};