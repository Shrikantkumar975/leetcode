class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        int curr=0;

        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            nums[i]=abs((curr-sum)+temp);
            curr+=temp;
            sum-=temp;
        }

        return nums;
    }
};