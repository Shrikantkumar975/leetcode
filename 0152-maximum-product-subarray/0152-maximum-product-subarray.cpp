class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pp(n, 0);
        vector<int> sp(n, 0);

        pp[0] = nums[0];
        sp[n-1] = nums[n-1];

        // prefix product
        for(int i = 1; i < n; i++){
            if(nums[i] == 0)
                pp[i] = 0;
            else
                pp[i] = (pp[i-1] == 0 ? nums[i] : nums[i] * pp[i-1]);
        }

        // suffix product
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] == 0)
                sp[i] = 0;
            else
                sp[i] = (sp[i+1] == 0 ? nums[i] : nums[i] * sp[i+1]);
        }

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, max(pp[i], sp[i]));
        }

        return maxi;
    }
};
