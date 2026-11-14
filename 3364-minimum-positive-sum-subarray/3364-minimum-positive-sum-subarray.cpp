class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        int n=nums.size();

        vector<int> pre(n,0);
        pre[0]=nums[0];

        for(int i=1;i<n;i++)
            pre[i]=nums[i]+pre[i-1];
        
        for(int i=0;i<n;i++){
            for(int j=i+l-1;j<n && j<i+r;j++){
                int curr = pre[j]-pre[i]+nums[i];
                if( curr > 0){
                    ans=min(ans,curr);
                }
            }
        }

        if(ans == INT_MAX) return -1;

        return ans;
    }
};