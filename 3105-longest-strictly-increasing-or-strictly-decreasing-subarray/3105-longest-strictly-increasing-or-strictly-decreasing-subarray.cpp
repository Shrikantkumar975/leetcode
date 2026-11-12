class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si=1;
        int sd=1;

        int curri=1;
        int currd=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                curri++;
                si=max(si,curri);
            }else{
                curri=1;
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                currd++;
                sd=max(sd,currd);
            }else{
                currd=1;
            }
        }

        return max(si,sd);


    }
};