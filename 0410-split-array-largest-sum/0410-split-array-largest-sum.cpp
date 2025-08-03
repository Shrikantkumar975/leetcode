class Solution {
public:

    int check(vector<int> nums,int k,int mid){
        int s=1,mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(mx+nums[i]<=mid){
                mx+=nums[i];
            }else{
                s++;
                mx = nums[i];
            }
        }

        return s;
    }

    int splitArray(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;

            int a = check(nums,k,mid);

            if(a<=k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};