class Solution {
public:
    vector<int> par, size;

    int find(int x) {
        if (par[x] == x)
            return x;

        return par[x] = find(par[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }
    }

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        par.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            par[i] = i;

        // value, original index
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        // Make components
        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i-1].first <= limit)
                Union(v[i].second, v[i-1].second);
        }

        // Put indices of same component together
        vector<vector<int>> groups(n);

        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        // For every component
        for (auto &indices : groups) {

            if (indices.empty()) continue;

            vector<int> values;

            for (int idx : indices)
                values.push_back(nums[idx]);

            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            for (int i = 0; i < indices.size(); i++)
                nums[indices[i]] = values[i];
        }

        return nums;
    }
};