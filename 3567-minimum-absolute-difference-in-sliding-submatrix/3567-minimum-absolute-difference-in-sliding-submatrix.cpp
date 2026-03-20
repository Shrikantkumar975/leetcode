class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans;

        for (int i = 0; i <= m - k; i++) {
            vector<int> curr;
            for (int j = 0; j <= n - k; j++) {
                vector<int> v;
                for (int p = i; p < i + k; p++) {
                    for (int q = j; q < j + k; q++) {
                        v.push_back(grid[p][q]);
                    }
                }
                sort(v.begin(), v.end());

                auto last = unique(v.begin(), v.end());
                v.erase(last, v.end());

                int mini = INT_MAX;

                if (v.size() <= 1)
                    mini = 0;
                else
                    for (int p = 1; p < v.size(); p++) {
                        mini = min(mini, v[p] - v[p - 1]);
                    }
                curr.push_back(mini);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};