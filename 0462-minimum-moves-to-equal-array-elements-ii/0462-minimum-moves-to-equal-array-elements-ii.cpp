class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int mid = nums[n/2];
        int total = 0;
        
        for(int a: nums){
            total+=abs(a-mid);
        }

        return total;
    }
};