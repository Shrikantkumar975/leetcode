class Solution {
public:
    int MOD = 1e9 +7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i =0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int v=queries[i][3];

            while(l<=r){
                long long curr = (1LL*nums[l]*v)%MOD;
                nums[l] = (int)curr;
                l+=k;
            }
        }

        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }

        return ans;
    }
};