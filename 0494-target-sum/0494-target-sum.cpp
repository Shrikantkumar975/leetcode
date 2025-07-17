class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9 + 7;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((target+sum)%2!=0 || abs(target)>sum) return 0;
        target = (target + sum)/2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        

        for (int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % mod;
                else    
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][target];
    }
};