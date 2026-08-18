class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int ans = -1;
        int n = nums.size();

        if(k == n) {
            for(int x : nums)
                ans = max(ans, x);
            return ans;
        }

        for(int i = 0; i < n; i++) {
            int left = max(0, i-k+1);
            int right = min(i, n-k);

            int curr = right - left + 1;

            mpp[nums[i]] += curr;
        }

        for(auto &m : mpp) {
            if(m.second == 1)
                ans = max(ans, m.first);
        }

        return ans;
    }
};