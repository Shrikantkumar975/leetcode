class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> arr(nums.size()+1,0);
        //arr[i] = max. stolen money till house i

        arr[0]=0;
        arr[1]=nums[0];

        for(int i=2;i<=nums.size();i++){
            arr[i]=max(arr[i-1],nums[i-1]+arr[i-2]);
        }

        return arr[nums.size()];
    }
};