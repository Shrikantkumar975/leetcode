class Solution {
public:
    int arr[201][201][201];
    int MOD = 1e9+7;
    int solve(vector<int> &nums,int i, int first,int second){
        if(i==nums.size()){
            if(first!=0 && second!=0 && first==second){
                return 1;
            }
            return 0;
        }

        if(arr[i][first][second]!=-1) return arr[i][first][second];

        int skip = solve(nums,i+1,first,second);
        int take1 = solve(nums,i+1,gcd(first,nums[i]),second);
        int take2 = solve(nums,i+1,first,gcd(second,nums[i]));

        return arr[i][first][second] = (0LL+skip + take1 + take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(arr,-1,sizeof(arr));

        return solve(nums,0,0,0);
    }
};