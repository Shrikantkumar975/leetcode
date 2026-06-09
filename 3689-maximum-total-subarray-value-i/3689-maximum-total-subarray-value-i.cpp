class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;

        int ma = *max_element(begin(nums),end(nums));
        int mi = *min_element(begin(nums),end(nums));

        return ans = (long long)(ma - mi)*k;
    }
};