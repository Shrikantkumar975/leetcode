class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int curr = 1;
        int prev = 0;
        int ans =0;

        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                curr+=1;
            }else{
                int a = curr/2;
                a = max(a,prev);
                ans = max(ans,a);

                prev=curr;
                curr=1;
            }
        }
        int b=curr/2;
        b = max(b,prev);

        ans = max(b,ans);

        return ceil(ans/2.0);
    }
};