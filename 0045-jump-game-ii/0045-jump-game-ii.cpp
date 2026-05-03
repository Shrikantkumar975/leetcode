class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()  == 1) return 0;
        int count =0, farthest= 0, stop =0;

        for(int i = 0;i<nums.size()-1;i++){
            farthest = max(farthest,nums[i] + i);

            if(farthest >= nums.size()-1){
                count++;
                break;
            }

            if(i == stop){
                count++;
                stop = farthest;
            }
        }

        return count;
    }
};