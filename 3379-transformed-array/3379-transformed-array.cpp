class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> result(n);

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                result[i]=nums[(i+nums[i])%n];
            }else{
                result[i]=nums[(n+i-abs(nums[i]))%n];
            }
        }

        return result;
    }
};