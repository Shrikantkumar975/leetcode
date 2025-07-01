class Solution {
public:
    bool fun(vector<int>&nums,int mid,int t){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/mid);
        }

        if(sum<=t) return 1;
        return 0;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int mx = nums[0];

        for(int i=0;i<nums.size();i++){
            mx = max(nums[i],mx);
        }

        int low = 1;
        int high = mx;
        int ans =-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(fun(nums,mid,threshold)){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};