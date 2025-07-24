class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        
        int ans=1;
        int count=1;

        for(int i=1;i<nums.size();i++){
            if((nums[i]-nums[i-1])==1) count++;
            else{
                ans = max(ans,count);
                count=1;
            }
        }

        return max(ans,count);
    }
};