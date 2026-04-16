class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        vector<int> arr = nums;
        for (int x : nums) arr.push_back(x);

        int m = arr.size();

        vector<int> left(m, INT_MAX);
        vector<int> right(m, INT_MAX);

        unordered_map<int, int> mpp;

        // left pass
        for (int i = 0; i < m; i++) {
            if (mpp.find(arr[i]) != mpp.end()) {
                left[i] = i - mpp[arr[i]];
            }
            mpp[arr[i]] = i;
        }

        mpp.clear();

        // right pass
        for (int i = m - 1; i >= 0; i--) {
            if (mpp.find(arr[i]) != mpp.end()) {
                right[i] = mpp[arr[i]] - i;
            }
            mpp[arr[i]] = i;
        }

        vector<int> ans;

        for (int q : queries) {
            int res = INT_MAX;

            // check all possible relevant positions
            int idx1 = q;
            int idx2 = q + n;

            // try both copies
            for (int idx : {idx1, idx2}) {
                if (left[idx] != INT_MAX) {
                    int d = left[idx];
                    res = min(res, min(d, n - d));
                }
                if (right[idx] != INT_MAX) {
                    int d = right[idx];
                    res = min(res, min(d, n - d));
                }
            }

            if (res == 0) ans.push_back(-1);
            else ans.push_back(res);
        }

        return ans;
    }
};